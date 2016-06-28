#include <iostream>

using namespace std;

enum LOCATION
{
	A, B
};

enum STATUS
{
	CLEAN, DIRTY
};

enum ACTION
{
	NOOP, RIGHT, LEFT, SUCK
};

class Percept {
	LOCATION _location;
	STATUS _status;
public:
	Percept();
	Percept(LOCATION, STATUS);
	void setLocation(LOCATION);
	void setStatus(STATUS);
	void setLocationAndStatus(LOCATION, STATUS);
	LOCATION getLocation() const;
	STATUS getStatus() const;
	void printLocation();
	void printStatus();		
	bool operator==(const Percept&);
};

Percept::Percept() {
	_location = A;
	_status = CLEAN;
}

Percept::Percept(LOCATION location, STATUS status) {
	_location = location;
	_status = status;
}

void Percept::setLocation(LOCATION location) {
	_location = location;
}

void Percept::setStatus(STATUS status) {
	_status = status;
}

void Percept::setLocationAndStatus(LOCATION location, STATUS status) {
	_location = location;
	_status = status;
}

LOCATION Percept::getLocation() const {
	return _location;
}

STATUS Percept::getStatus() const {
	return _status;
}

void Percept::printLocation()  {
	if(_location == A) cout <<  "Location: ROOM A" << endl;
	else if(_location == B) cout << "Location: ROOM B" << endl;
}

void Percept::printStatus()  {
	if(_status == CLEAN) cout << "Status: CLEAN" << endl;
	else if(_status == DIRTY) cout << "Status: DIRTY" << endl;
}

bool Percept::operator==(const Percept& percept) {
	return _location == percept.getLocation() && _status == percept.getStatus();
}


class Sequence {
	Percept _percepts[2];
	ACTION _action;
	int _sequenceLength;
public:
	Sequence();
	void add(Percept[], ACTION, int);
	void addPercept(Percept);
	int getSequenceLength();
	Percept getPerceptAt(int);
	ACTION getAction();
};

Sequence::Sequence() {
	_action = NOOP;
	_sequenceLength = 0;
}

void Sequence::add(Percept percepts[], ACTION action, int sequenceLength) {
	for (int i = 0; i < sequenceLength; ++i) {
		_percepts[i] = percepts[i];
	}
	_action = action;
	_sequenceLength = sequenceLength;
}

void Sequence::addPercept(Percept percept) {
	if(_sequenceLength > 1) _sequenceLength = 0;	
	_percepts[_sequenceLength] = percept;
	_sequenceLength++;
}

int Sequence::getSequenceLength() {
	return _sequenceLength;
}

Percept Sequence::getPerceptAt(int index) {
	//TODO: make sure this doesnt errors for index out of bound 
	return _percepts[index];
}

ACTION Sequence::getAction() {
	return _action;
}

class AgentTable {
	// there can be 20 different sequences if we go up to 4x4 states 
	// for e.g. one of these sequence can be {[A, Clean], [A, Clean]} => RIGHT
	Sequence _sequences[20];
public:
	AgentTable();
	void addSequenceAt(Sequence, int index);
	ACTION getActionForSequence(Sequence);
};

AgentTable::AgentTable() {
	cout << endl << "Agent Table Initialized" << endl;
	Sequence sequence;

	// 4 states
	Percept* percepts = new Percept[1];

	Percept percept(A,CLEAN);
	percepts[0] = percept;
	sequence.add(percepts, RIGHT, 1);
	addSequenceAt(sequence, 0);

	percept.setLocation(A);
	percept.setStatus(DIRTY);
	percepts[0] = percept;
	sequence.add(percepts, SUCK, 1);
	addSequenceAt(sequence, 1);	

	percept.setLocation(B);
	percept.setStatus(CLEAN);
	percepts[0] = percept;
	sequence.add(percepts, LEFT, 1);
	addSequenceAt(sequence, 2);	

	percept.setLocation(B);
	percept.setStatus(DIRTY);
	percepts[0] = percept;
	sequence.add(percepts, SUCK, 1);
	addSequenceAt(sequence, 3);	

	// 4*4 states
	percepts = new Percept[2];

	percept.setLocation(A);
	percept.setStatus(CLEAN);
	percepts[0] = percept;	
	percepts[1] = percept;	
	sequence.add(percepts, RIGHT, 2);
	addSequenceAt(sequence, 4);		

	percept.setLocation(A);
	percept.setStatus(CLEAN);
	percepts[0] = percept;	
	percept.setStatus(DIRTY);
	percepts[1] = percept;	
	sequence.add(percepts, SUCK, 2);
	addSequenceAt(sequence, 5);	

	percept.setLocation(A);
	percept.setStatus(CLEAN);
	percepts[0] = percept;	
	percept.setLocation(B);
	percept.setStatus(CLEAN);	
	percepts[1] = percept;	
	sequence.add(percepts, LEFT, 2);
	addSequenceAt(sequence, 6);	

	percept.setLocation(A);
	percept.setStatus(CLEAN);
	percepts[0] = percept;	
	percept.setLocation(B);	
	percept.setStatus(DIRTY);
	percepts[1] = percept;	
	sequence.add(percepts, SUCK, 2);
	addSequenceAt(sequence, 7);	

	percept.setLocation(A);
	percept.setStatus(DIRTY);
	percepts[0] = percept;	
	percept.setStatus(CLEAN);
	percepts[1] = percept;	
	sequence.add(percepts, RIGHT, 2);
	addSequenceAt(sequence, 8);		

	percept.setLocation(A);
	percept.setStatus(DIRTY);
	percepts[0] = percept;	
	percept.setStatus(DIRTY);
	percepts[1] = percept;	
	sequence.add(percepts, SUCK, 2);
	addSequenceAt(sequence, 9);	

	percept.setLocation(A);
	percept.setStatus(DIRTY);
	percepts[0] = percept;
	percept.setLocation(B);	
	percept.setStatus(CLEAN);
	percepts[1] = percept;	
	sequence.add(percepts, LEFT, 2);
	addSequenceAt(sequence, 10);	

	percept.setLocation(A);
	percept.setStatus(DIRTY);
	percepts[0] = percept;
	percept.setLocation(B);	
	percept.setStatus(DIRTY);
	percepts[1] = percept;	
	sequence.add(percepts, SUCK, 2);
	addSequenceAt(sequence, 11);	

	percept.setLocation(B);
	percept.setStatus(CLEAN);
	percepts[0] = percept;	
	percept.setLocation(A);
	percept.setStatus(CLEAN);	
	percepts[1] = percept;	
	sequence.add(percepts, RIGHT, 2);
	addSequenceAt(sequence, 12);	

	percept.setLocation(B);
	percept.setStatus(CLEAN);
	percepts[0] = percept;	
	percept.setLocation(A);	
	percept.setStatus(DIRTY);
	percepts[1] = percept;	
	sequence.add(percepts, SUCK, 2);
	addSequenceAt(sequence, 13);	

	percept.setLocation(B);
	percept.setStatus(CLEAN);
	percepts[0] = percept;	
	percepts[1] = percept;	
	sequence.add(percepts, LEFT, 2);
	addSequenceAt(sequence, 14);		

	percept.setLocation(B);
	percept.setStatus(CLEAN);
	percepts[0] = percept;	
	percept.setStatus(DIRTY);
	percepts[1] = percept;	
	sequence.add(percepts, SUCK, 2);
	addSequenceAt(sequence, 15);	

	percept.setLocation(B);
	percept.setStatus(DIRTY);
	percepts[0] = percept;
	percept.setLocation(A);	
	percept.setStatus(CLEAN);
	percepts[1] = percept;	
	sequence.add(percepts, RIGHT, 2);
	addSequenceAt(sequence, 16);

	percept.setLocation(B);
	percept.setStatus(DIRTY);
	percepts[0] = percept;
	percept.setLocation(A);	
	percept.setStatus(DIRTY);
	percepts[1] = percept;	
	sequence.add(percepts, SUCK, 2);
	addSequenceAt(sequence, 17);	

	percept.setLocation(B);
	percept.setStatus(DIRTY);
	percepts[0] = percept;	
	percept.setStatus(CLEAN);
	percepts[1] = percept;	
	sequence.add(percepts, LEFT, 2);
	addSequenceAt(sequence, 18);		

	percept.setLocation(B);
	percept.setStatus(DIRTY);
	percepts[0] = percept;	
	percept.setStatus(DIRTY);
	percepts[1] = percept;	
	sequence.add(percepts, SUCK, 2);
	addSequenceAt(sequence, 19);	
											
}

void AgentTable::addSequenceAt(Sequence sequence, int index) {
	_sequences[index] = sequence;
}

ACTION AgentTable::getActionForSequence(Sequence sequence) {
	
	bool match = true;
	
	ACTION action = NOOP;

	for (int i = 0; i < 84; ++i) {

		// assume this sequence will match with the given sequence
		match = true;

		for (int j = 0; j < sequence.getSequenceLength(); ++j) {
			match = _sequences[i].getSequenceLength() == sequence.getSequenceLength() && _sequences[i].getPerceptAt(j) == sequence.getPerceptAt(j);
			// we must stop even if one of the percept doesnt match
			if(!match) break;
		}

		// match still true means all the percepts matched, time to fetch the action and return it to the agent
		if(match) {
			action = _sequences[i].getAction();
			break;
		}
	}

	return action;
}

class Agent {
	Sequence _sequence;
	AgentTable _table;

public:
	Agent();
	ACTION execute(Percept percept);
};

Agent::Agent() {
	cout << endl << "Vacuum Robot Agent Initialized" << endl;
}

ACTION Agent::execute(Percept percept) {
	_sequence.addPercept(percept);
	cout << endl << "Current Percept Sequence" << endl;
	for (int i = 0; i < _sequence.getSequenceLength(); ++i)
	{
		_sequence.getPerceptAt(i).printLocation();
		_sequence.getPerceptAt(i).printStatus();
	}	
	return _table.getActionForSequence(_sequence);
}

void printAction(ACTION action) {
	if(action == 0) cout << "Action : NOOP" << endl;
	else if(action == 1) cout << "Action : MOVE RIGHT" << endl;
	else if(action == 2) cout << "Action : MOVE LEFT" << endl;
	else if(action == 3) cout << "Action : SUCK DIRT" << endl;
}

int main() {
	Agent vacuumRobot;
	Percept percept(A,DIRTY);
	ACTION action = vacuumRobot.execute(percept);
	printAction(action);
	percept.setLocationAndStatus(A, CLEAN);
	action = vacuumRobot.execute(percept);
	printAction(action);
	percept.setLocationAndStatus(B, DIRTY);
	action = vacuumRobot.execute(percept);
	printAction(action);	
	percept.setLocationAndStatus(B, CLEAN);
	action = vacuumRobot.execute(percept);
	printAction(action);		
	return 0;
}

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
	NOOP, RIGHT, LEFT , SUCK
};

class Percept {
	LOCATION _location;
	STATUS _status;
public:
	Percept();
	Percept(LOCATION, STATUS);
	void setLocation(LOCATION);
	void setStatus(STATUS);
	LOCATION getLocation();
	STATUS getStatus();	
	bool operator==(Percept&);
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

LOCATION Percept::getLocation() {
	return _location;
}

STATUS Percept::getStatus() {
	return _status;
}

bool Percept::operator==(Percept& percept) {
	return _location == percept.getLocation() && _status == percept.getStatus();
}


class Sequence {
	Percept _percepts[3];
	ACTION _action;
	int _sequenceLength;
public:
	Sequence();
	void add(Percept[], ACTION, int);
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
	// there can be 84 different sequences if we go up to 4x4x4 states 
	// for e.g. one of these sequence can be {[A, Clean], [A, Clean], [A, Clean]} => RIGHT
	Sequence sequences[84];
public:
	AgentTable();
	void addSequenceAt(Sequence, int index);
	ACTION getActionForSequence(Sequence);
};

AgentTable::AgentTable() {
	cout << "Agent Table Initialized" << endl;
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
}

void AgentTable::addSequenceAt(Sequence sequence, int index) {
	sequences[index] = sequence;
}

ACTION AgentTable::getActionForSequence(Sequence sequence) {
	
	bool match = true;
	
	ACTION action = NOOP;

	for (int i = 0; i < 84; ++i) {

		// assume this sequence will match with the given sequence
		match = true;

		for (int j = 0; j < sequence.getSequenceLength(); ++j) {
			match = _sequences[i]._percepts[j] == sequence.getPerceptAt(j);
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

int main() {
	cout << "Table Driven Vacuum Cleaner Agent" << endl;
	AgentTable table;
	return 0;
}

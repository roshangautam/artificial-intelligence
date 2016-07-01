//
//  WumpusEnvironment.cpp
//  Wumpus World
//
//  Created by Roshan Gautam on 6/30/16.
//  Copyright © 2016 Roshan Gautam. All rights reserved.
//

#include "WumpusEnvironment.h"

using namespace std;

WumpusEnvironment::WumpusEnvironment() {

    for (int i = 0; i < 16; ++i) {
        breezePositions[i] = -1;
        stenchPositions[i] = -1;
    }

    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j) wumpusWorld[i][j] =  "";

    int count = 1;
	
	cout << "Knowlege Based Agent Demonstration - Wumpus World" << endl;
    
    for (int i = 0; i < 4; ++i) {
        cout << endl;
        for (int j = 0; j < 4; ++j) 
        	cout << count++ << "\t|\t";
    }

    cout << endl;

    wumpusWorld[3][0] = "A";

    renderWorld();

	cout << "Enter Number of pits: ";
	cin >> pitCount;
	pitPositions = new int[pitCount];
	
	for (int i = 0; i < pitCount; ++i) {
		cout << "Enter the position of pit " << i + 1 << " and hit enter : ";
		cin >> pitPositions[i];
		addThreat(pitPositions[i], PIT);
	}

	cout << "Enter the position of Wumpus: ";
	cin >> wumpusPosition;
	addThreat(wumpusPosition, WUMPUS);

	cout << "Enter the position of gold: ";
	cin >> goldPosition;
	addGold();

	renderWorld();
}


void WumpusEnvironment::addThreat(int position, Threat threat) {
    int neighbors[4];
    neighbors[0] = position - 1;
    neighbors[1] = position + 1;
    neighbors[2] = position + 4;
    neighbors[3] = position - 4;

    if (position == 5 || position == 9) neighbors[0] = 0;
    if (position == 8 || position == 12) neighbors[1] = 0;
    if (position == 4) neighbors[1] = 0;
    if (position == 13) neighbors[0] = 0;
    if (neighbors[2] > 16) neighbors[2] = 0;
    if (neighbors[3] < 0) neighbors[3] = 0;


    if (threat == PIT) {
    	for (int i = 0; i < 4; ++i)
    		breezePositions[i] = neighbors[i];
    } else if(threat == WUMPUS) {
    	for (int i = 0; i < 4; ++i)
    		stenchPositions[i] = neighbors[i];
    }

    int temp1, count;

    for (int i = 0; i < 4; ++i) {

        if (threat == PIT) temp1 = breezePositions[i];

        else temp1 = stenchPositions[i];

        count = 0;

        for (int j = 0; j < 4; ++j) {

            for (int k = 0; k < 4; ++k) {

                ++count;

                if (count == temp1 && threat == PIT && wumpusWorld[j][k].find("B") == string::npos)
                	
                	wumpusWorld[j][k].append("B");

                else if (count == temp1 && threat == WUMPUS && wumpusWorld[j][k].find("S") == string::npos) 

                	wumpusWorld[j][k].append("S");
            }
        }
    }	
}

void WumpusEnvironment::addGold() {
    int temp = 0;
    int count = 0;
    int flag1 = 0, flag2 = 0;
    for (int i = 0; i < pitCount; ++i) {
        temp = pitPositions[i];
        count = 0;
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                ++count;
                if (count == temp) wumpusWorld[j][k].append("P");
                else if (count == goldPosition && flag1 == 0) {
                    wumpusWorld[j][k].append("G");
                    flag1 = 1;
                } else if (count == wumpusPosition && flag2 == 0) {
                    wumpusWorld[j][k].append("W");
                    flag2 = 1;
                }
            }
        }
    }
}

void WumpusEnvironment::renderWorld() {

	cout << "Current State Of The World";

    for (int i = 0; i < 4; ++i) {
        cout << endl;
        for (int j = 0; j < 4; ++j) 
        	cout << wumpusWorld[i][j] << "\t|\t";
        cout << endl;
    }

    cout << endl;	
}

string WumpusEnvironment::getRoomInWorld(int i, int j) {
	return wumpusWorld[i][j];
}

CaveRoom::CaveRoom() {
    safe = 0;
    unsafe = 0;
    wump = 0;
    pit = 0;
    gold = 0;
    doubt_pit = 0;
    doubt_wump = 0;
    room = "";
    num = 0;
    br = 0;
    bl = 0;
    bu = 0;
    bd = 0;
    visited = 0;	
}

void CaveRoom::init(string s, int n) {
    room = s;
    num = n;
    l = r = u = d = 0;
    if (n == 9 || n == 5) bl = 1;
    if (n == 8 || n == 12) br = 1;
    if (n == 1) {
        bu = 1;
        bl = 1;
    }
    if (n == 13) {
        bd = 1;
        bl = 1;
    }
    if (n == 4) {
        bu = 1;
        br = 1;
    }
    if (n == 16) {
        bd = 1;
        br = 1;
    }	
}

void CaveRoom::setSafe(int isSafe) {
	safe = isSafe;
}

int CaveRoom::isSafe() {
	return safe;
}

void CaveRoom::setVisited(int hasVisited) {
	visited = hasVisited;
}

int CaveRoom::hasVisited() {
	return visited;
}

int CaveRoom::sense() {
    if (room.find("B") != string::npos) 
    	return 1;
    else if (room.find("S") != string::npos) 
    	return 2;
    else if (room.find("G") != string::npos) 
    	return 3;
	if (room.find("W") != string::npos) 
		return 4;
	else 
		return 0;
}

Agent::Agent() {
	scream = 0;
	score = 0;
	complete = 0;
}

bool Agent::check(CaveRoom room) {
    int temp = room.sense();
    if (temp == 1 || temp == 2) return false;
    return true;	
}

void Agent::execute() {

	CaveRoom rooms[16];

    int c = 1;
	int wpos,spos;

   	out:for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (c > 16) goto out;
            rooms[c].init(environment.getRoomInWorld(i,j), c);
            ++c;
        }
    }

    rooms[13].setSafe(1);
    rooms[13].setVisited(1);

    int pos = 13;
    int condition;
    int limit = 0;
    string temp1, temp2;
    do {
        ++limit;
        condition = -1;

        if (rooms[pos].room.find("G") != string::npos) {
            complete = 1;
            cout << "Oh my its glittery. Gold Found" << endl;
            break;
        }

        if (rooms[pos].br != 1 && rooms[pos].r != 1 && rooms[pos + 1].doubt_pit < 1 && rooms[pos + 1].doubt_wump < 1 && rooms[pos + 1].pit != 1 && rooms[pos + 1].wump != 1 && !(rooms[pos].back.find("r") != string::npos && (rooms[pos].l != 1 || rooms[pos].u != 1 || rooms[pos].d != 1) && check(rooms[pos]))) {
            
            temp1 = "l";
            
            rooms[pos].r = 1;
            ++pos;
            
            cout << "Moving Right to " << pos << endl;
            
            ++score;
            
            rooms[pos].back += temp1;
            
            condition = rooms[pos].sense();
            if (condition == 3) {
                complete = 1;
                break;
            } else if (condition == 1 && !rooms[pos].hasVisited()) {
                if (rooms[pos].br != 1 && !rooms[pos + 1].isSafe()) rooms[pos + 1].doubt_pit += 1;
                if (rooms[pos].bu != 1 && (pos - 4) >= 1 && rooms[pos - 4].safe != 1) rooms[pos - 4].doubt_pit += 1;
                if (rooms[pos].bl != 1 && rooms[pos - 1].safe != 1) rooms[pos - 1].doubt_pit += 1;
                if (rooms[pos].bd != 1 && (pos + 4) < 16 && rooms[pos + 4].safe != 1) rooms[pos + 4].doubt_pit += 1;
                rooms[pos].safe = 1;
            } else if (condition == 2 && !rooms[pos].hasVisited()) {
                if (rooms[pos].br != 1 && rooms[pos + 1].safe != 1) rooms[pos + 1].doubt_wump += 1;
                if (rooms[pos].bu != 1 && (pos - 4) >= 1 && rooms[pos - 4].safe != 1) rooms[pos - 4].doubt_wump += 1;
                if (rooms[pos].bl != 1 && rooms[pos - 1].safe != 1) rooms[pos - 1].doubt_wump += 1;
                if (rooms[pos].bd != 1 && (pos + 4) < 16 && rooms[pos + 4].safe != 1) rooms[pos + 4].doubt_wump += 1;
                rooms[pos].safe = 1;
            }
            
            else if (condition == 0) rooms[pos].safe = 1;
            rooms[pos].visited = 1;

        } else if (rooms[pos].bl != 1 && rooms[pos].l != 1 && rooms[pos - 1].doubt_pit < 1 && rooms[pos - 1].doubt_wump < 1 && rooms[pos - 1].pit != 1 && rooms[pos - 1].wump != 1 && !(rooms[pos].back.find("l") != string::npos && (rooms[pos].r != 1 || rooms[pos].u != 1 || rooms[pos].d != 1) && check(rooms[pos]))) {
            
            temp1 = "r";
            
            rooms[pos].l = 1;
            
            pos = pos - 1;
            
            cout << "Moving Left to " << pos << endl;
            
            ++score;
            
            rooms[pos].back += temp1;
            
            condition = rooms[pos].sense();
            if (condition == 3) {
                complete = 1;
                break;
            } else if (condition == 1 && rooms[pos].visited == 0) {
                if (rooms[pos].br != 1 && rooms[pos + 1].safe != 1) rooms[pos + 1].doubt_pit += 1;
                if (rooms[pos].bu != 1 && (pos - 4) >= 1 && rooms[pos - 4].safe != 1) rooms[pos - 4].doubt_pit += 1;
                if (rooms[pos].bl != 1 && rooms[pos - 1].safe != 1) rooms[pos - 1].doubt_pit += 1;
                if (rooms[pos].bd != 1 && (pos + 4) < 16 && rooms[pos + 4].safe != 1) rooms[pos + 4].doubt_pit += 1;
                rooms[pos].safe = 1;
            } else if (condition == 2 && rooms[pos].visited == 0) {
                if (rooms[pos].br != 1 && rooms[pos + 1].safe != 1) rooms[pos + 1].doubt_wump += 1;
                if (rooms[pos].bu != 1 && (pos - 4) >= 1 && rooms[pos - 4].safe != 1) rooms[pos - 4].doubt_wump += 1;
                if (rooms[pos].bl != 1 && rooms[pos - 1].safe != 1) rooms[pos - 1].doubt_wump += 1;
                if (rooms[pos].bd != 1 && (pos + 4) < 16 && rooms[pos + 4].safe != 1) rooms[pos + 4].doubt_wump += 1;
                rooms[pos].safe = 1;
            } else if (condition == 0) rooms[pos].safe = 1;
            rooms[pos].visited = 1;
        } else if (rooms[pos].bu != 1 && rooms[pos].u != 1 && (pos - 4) >= 1 && rooms[pos - 4].doubt_pit < 1 && rooms[pos - 4].doubt_wump < 1 && rooms[pos - 4].pit != 1 && rooms[pos - 1].wump != 1 && !(rooms[pos].back.find("u") != string::npos && (rooms[pos].l != 1 || rooms[pos].r != 1 || rooms[pos].d != 1) && check(rooms[pos]))) {
            
            temp1 = "d";
            
            rooms[pos].u = 1;
            pos = pos - 4;

            cout << "Moving Up to " << pos << endl;
            
            ++score;
           
            rooms[pos].back += temp1;
            
            condition = rooms[pos].sense();
            if (condition == 3) {
                complete = 1;
                break;
            } else if (condition == 1 && rooms[pos].visited == 0) {
                if (rooms[pos].br != 1 && rooms[pos + 1].safe != 1) rooms[pos + 1].doubt_pit += 1;
                if (rooms[pos].bu != 1 && (pos - 4) >= 1 && rooms[pos - 4].safe != 1) rooms[pos - 4].doubt_pit += 1;
                if (rooms[pos].bl != 1 && rooms[pos - 1].safe != 1) rooms[pos - 1].doubt_pit += 1;
                if (rooms[pos].bd != 1 && (pos + 4) < 16 && rooms[pos + 4].safe != 1) rooms[pos + 4].doubt_pit += 1;
                rooms[pos].safe = 1;
            } else if (condition == 2 && rooms[pos].visited == 0) {
                if (rooms[pos].br != 1 && rooms[pos + 1].safe != 1) rooms[pos + 1].doubt_wump += 1;
                if (rooms[pos].bu != 1 && (pos - 4) >= 1 && rooms[pos - 4].safe != 1) rooms[pos - 4].doubt_wump += 1;
                if (rooms[pos].bl != 1 && rooms[pos - 1].safe != 1) rooms[pos - 1].doubt_wump += 1;
                if (rooms[pos].bd != 1 && (pos + 4) < 16 && rooms[pos + 4].safe != 1) rooms[pos + 4].doubt_wump += 1;
                rooms[pos].safe = 1;
            } else if (condition == 0) rooms[pos].safe = 1;
            rooms[pos].visited = 1;
        } else if (rooms[pos].bd != 1 && rooms[pos].d != 1 && (pos + 4) < 16 && rooms[pos + 4].doubt_pit < 1 && rooms[pos + 4].doubt_wump < 1 && rooms[pos + 4].pit != 1 && rooms[pos + 4].wump != 1) {
            
            temp1 = "u";
            
            rooms[pos].d = 1;
            pos = pos + 4;

            cout << "Moving Down to " << pos << endl;

            ++score;
            
            rooms[pos].back += temp1;
            
            condition = rooms[pos].sense();
            if (condition == 3) {
                complete = 1;
                break;
            } else if (condition == 1 && rooms[pos].visited == 0) {
                if (rooms[pos].br != 1 && rooms[pos + 1].safe != 1) rooms[pos + 1].doubt_pit += 1;
                if (rooms[pos].bu != 1 && (pos - 4) >= 1 && rooms[pos - 4].safe != 1) rooms[pos - 4].doubt_pit += 1;
                if (rooms[pos].bl != 1 && rooms[pos - 1].safe != 1) rooms[pos - 1].doubt_pit += 1;
                if (rooms[pos].bd != 1 && (pos + 4) < 16 && rooms[pos + 4].safe != 1) rooms[pos + 4].doubt_pit += 1;
                rooms[pos].safe = 1;
            } else if (condition == 2 && rooms[pos].visited == 0) {
                if (rooms[pos].br != 1 && rooms[pos + 1].safe != 1) rooms[pos + 1].doubt_wump += 1;
                if (rooms[pos].bu != 1 && (pos - 4) >= 1 && rooms[pos - 4].safe != 1) rooms[pos - 4].doubt_wump += 1;
                if (rooms[pos].bl != 1 && rooms[pos - 1].safe != 1) rooms[pos - 1].doubt_wump += 1;
                if (rooms[pos].bd != 1 && (pos + 4) < 16 && rooms[pos + 4].safe != 1) rooms[pos + 4].doubt_wump += 1;
                rooms[pos].safe = 1;
            } else if (condition == 0) rooms[pos].safe = 1;
            rooms[pos].visited = 1;
        } else if (limit > 50) {
            int temp3 = pos;
            int flag_1 = 0, flag2 = 0, flag3 = 0, flag4 = 0;

            cout << "In Room " << temp3 << endl;
            
            
            while (rooms[pos].visited == 1 && rooms[pos].br != 1) {
                ++pos;
                ++score;
            }
            if (rooms[pos].pit == 1 || rooms[pos].wump == 1 || (rooms[pos].br == 1 && rooms[pos].visited == 1 && rooms[pos].safe != 1)) {
                
                pos = temp3;
                
                flag_1 = 1;
            }
            if (flag_1 == 0) rooms[pos].back += "l";
            
            while (pos + 4 >= 1 && rooms[pos].bu != 1 && rooms[pos].visited == 1) {
                pos -= 4;
                ++score;
            }
            if (rooms[pos].pit == 1 || rooms[pos].wump == 1 || (rooms[pos].bu == 1 && rooms[pos].visited == 1 && rooms[pos].safe != 1)) {
                
                pos = temp3;
                
                flag3 = 1;
            }
            if (flag3 == 0) rooms[pos].back += "d";
            
            while (rooms[pos].visited == 1 && rooms[pos].bl != 1) {
                --pos;
                ++score;
            }
            if (rooms[pos].pit == 1 || rooms[pos].wump == 1 || (rooms[pos].bl == 1 && rooms[pos].visited == 1 && rooms[pos].safe != 1)) {
                
                pos = temp3;
                
                flag2 = 1;
            }
            if (flag2 == 0) rooms[pos].back += "r";
            
            while (pos + 4 < 16 && rooms[pos].bd != 1 && rooms[pos].visited == 1) {
                pos += 4;
                ++score;
            }
            if (rooms[pos].pit == 1 || rooms[pos].wump == 1 || (rooms[pos].bd == 1 && rooms[pos].visited == 1 && rooms[pos].safe != 1)) {
                
                pos = temp3;
                
                flag4 = 1;
            }
            
            if (flag4 == 0) rooms[pos].back += "u";
            rooms[pos].safe = 1;
            rooms[pos].visited = 1;
            cout << "Arrived in Room " << pos << endl;
            
            limit = 0;
        }
        if (rooms[pos].room.find("W") != string::npos && scream != 1) {
            score += 100;
            scream = 1;
            rooms[pos].safe = 1;
            cout << "Woohoo. Wumpus is dead " << endl;
            wpos = rooms[pos].room.find("W");
            rooms[pos].room.replace(wpos, 1, " ");
            for (int l = 1; l < 16; ++l) {
                rooms[l].doubt_wump = 0;
                spos = rooms[l].room.find("S");
                rooms[l].room.replace(spos, 1, " ");
            }
        }
        if (rooms[pos].room.find("P") != string::npos) {
            score += 50;
            rooms[pos].pit = 1;
            cout << "Death By PIT in room " << pos << ". See you in After Life" <<  endl;
        }
        for (int k = 1; k < 16; ++k) {
            if (rooms[k].doubt_pit == 1 && rooms[k].doubt_wump == 1) {
                rooms[k].doubt_pit = 0;
                rooms[k].doubt_wump = 0;
                rooms[k].safe = 1;
            }
        }
        for (int y = 1; y < 16; ++y) {
            if (rooms[y].doubt_wump > 1) {
                rooms[y].wump = 1;
                for (int h = 1; h < 16; ++h) {
                    if (h != y) {
                        rooms[h].doubt_wump = 0;
                        spos = rooms[h].room.find("S");
                        rooms[h].room.replace(spos, 1, " ");
                    }
                }
            }
        }
        
        for (int y = 1; y < 16; ++y) {
            if (rooms[y].doubt_pit > 1) {
                rooms[y].pit = 1;
                
            }
        }

    }
    while (complete == 0);
    if (complete == 1) {
        score *= -1;
        score += 1000;
    }
    cout << "Utility Score is " << score << endl;
}
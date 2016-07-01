//
//  WumpusEnvironment.h
//  Wumpus World
//
//  Created by Roshan Gautam on 6/30/16.
//  Copyright © 2016 Roshan Gautam. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

enum Threat
{
	PIT,
	WUMPUS
};

class WumpusEnvironment {
	int pitCount;
	int wumpusPosition;
	int goldPosition; 
	int* pitPositions; 
	int breezePositions[16];
	int stenchPositions[16];
	string wumpusWorld[4][4];
public:
	WumpusEnvironment();
	void addThreat(int,Threat);
	void addGold();
	void renderWorld();
	string getRoomInWorld(int,int);
};


class CaveRoom
{
public:
    int safe;
    int unsafe;
    int wump;
    int pit;
    int gold;
    int doubt_pit;
    int doubt_wump;
    string room;
    int num;
    int br;
    int bl;
    int bu;
    int bd;
    int visited;
    int l, r, u, d;
    string back;		
	CaveRoom();
	void setSafe(int);
	int isSafe();
	void setVisited(int);
	int hasVisited();
	void init(string, int);
	int sense();	
};


class Agent
{
    int scream;
    int score;
    int complete;	
    WumpusEnvironment environment;
public:
	Agent();
	bool check(CaveRoom);
	void execute();
};


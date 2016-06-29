//
//  main.cpp
//  tree
//
//  Created by Roshan Gautam on 5/31/16.
//  Copyright © 2016 Roshan Gautam. All rights reserved.
//


#include <iostream>

#include <cstdlib>
#include <iomanip>
#include <cmath>

using namespace std;

int* tree;

enum level
{
    MIN, MAX
};


int main(int argc, char **argv) {
    
    int n, seed; 
    level state;

    cout << "Enter number of nodes to be generated. Please input number of nodes such that the tree is a complete tree for e.g. 15 or 31:";
    cin >> n;

    tree = new int[n];
    int leaves = (n + 1) / 2;
    int height = floor(log(n));
    int levels = height + 1;

    for (int i = 0; i < n; ++i)
    {
       tree[i] = INT_MAX;
    }

    cout << "Enter the seed value to generate random numbers:";
    cin >> seed;
	
	srand(seed);
    
    for (int i = 0; i < n; ++i) {
    	tree[i] = rand() % 100;
    }

    cout << "Initial Tree" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << tree[i] << endl;
    }
    
    level* levelStates = new level[levels];
    level currentState;

    for (int i = 0; i <= levels; ++i)
    {
        if(i == 0) {
          currentState = MAX;
        } else {
            if (currentState == MAX) currentState = MIN;
            else currentState = MAX;
        }
        levelStates[i] = currentState;   
    }

    int nodesLeft = n;

    // minimax - alphabeta
    for (int i = levels; i >= 0; i--)
    {
        int nodesInThisLevel = pow(2, i);
        int levelStart = nodesLeft - nodesInThisLevel;
        int levelEnd = levelStart + nodesInThisLevel;
        if(nodesInThisLevel > 1) { // if theres only 1 node in this level i.e. this is root level
            for (int j = levelStart; j < levelEnd; j+=2)
            {
                int parent = (j - 1 ) / 2 ;
                if(levelStates[i-1] == MIN) {
                    int alpha = tree[2*parent+1];
                    if(tree[2*parent+2] < alpha) alpha = tree[2*parent+2];
                    tree[parent] = alpha;
                }
                else if(levelStates[i-1] == MAX) {
                    int beta = tree[2*parent+1];
                    if(tree[2*parent+2] > beta) beta = tree[2*parent+2];
                    tree[parent] =beta;
                }
            }

            nodesLeft = nodesLeft - nodesInThisLevel; 
        }
    }
    
    cout << "Tree after MiniMax - AlphaBeta" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << tree[i] << endl;
    }
    cout << endl;
    return 0;
}





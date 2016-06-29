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

using namespace std;


int main(int argc, char **argv) {
    
    int* tree;

    int nodes, seed, count = 0; 

    cout << "Enter number of nodes to be generated:";
    cin >> nodes;

    tree = new int[nodes];

    cout << "Enter the seed value to generate random numbers:";
    cin >> seed;
	
	srand(seed);
    
    for (int i = 0; i < nodes; ++i) {
    	tree[i] = rand();
    }

// left_child = tree[2 * n + 1];
// right_child = tree[2 * n + 2];	
    return 0;
}






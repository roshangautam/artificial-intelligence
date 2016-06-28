//
//  AdjacencyMatrix.h
//  Graph
//
//  Created by Roshan Gautam on 6/20/16.
//  Copyright © 2016 Roshan Gautam. All rights reserved.
//

#pragma once

#ifndef AdjacencyMatrix_h
#define AdjacencyMatrix_h

#include <iostream>
#include <map>

#endif /* AdjacencyMatrix_h */

using namespace std;
typedef map<int, map<int, bool> > table;
class AdjacencyMatrix {

    // 26 by 26 matrix for each letters in english alphabets
    int vertices[26][26];

    // an array to keep track of visited vertices while traversing
    bool visited[26];

    // a map to keep track of explored vertices while traversing
    table explored;

public:
    AdjacencyMatrix();  
    void addEdge(int, int, int);
    void initVisited();
    void print();
    void DFT(int);
    void BFT(int);
    int DFS(int, int);
    int BFS(int, int);
    int UCS(int, int);
    int countChildren(int); 
    int* getChildren(int);   
};


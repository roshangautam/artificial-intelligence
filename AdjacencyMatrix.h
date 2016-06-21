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


#endif /* AdjacencyMatrix_h */

using namespace std;

class AdjacencyMatrix {

    // 26 by 26 matrix for each letters in english alphabets
    int vertices[26][26];

    // an array to keep track of visited vertices while traversing
    bool visited[26];

public:
    AdjacencyMatrix();  
    void addEdge(int, int, int);
    void initVisited();
    void print();
    void dft(int);
    void bft(int);
};


//
//  AdjacencyMatrix.cpp
//  Graph
//
//  Created by Roshan Gautam on 6/20/16.
//  Copyright © 2016 Roshan Gautam. All rights reserved.
//


#ifndef AdjacencyMatrix_cpp
#define AdjacencyMatrix_cpp

#include <iostream>
#include <climits>
#include "AdjacencyMatrix.h"
#include "Stack.h"
#include "Queue.h"
#endif /* AdjacencyMatrix_cpp */

using namespace std;

AdjacencyMatrix::AdjacencyMatrix() {
	
	cout << "AdjacencyMatrix Initialized" << endl;

	// set the distance between each city to a very high value to 
	// inidicate that they are not reachable 
	for (int i = 0; i < 26; ++i) {

		for (int j = 0; j < 26; ++j) {
			// setting the distance to a very high value
			// to inidicate these cities are not within reach
			vertices[i][j] = INT_MAX;
		}
	}

	initVisited();
}

void AdjacencyMatrix::initVisited() {

	// loop through the visited array and set everything to false
	for (int i = 0; i < 26; ++i) {

		visited[i] = false;
	}	
}

void AdjacencyMatrix::addEdge(int from, int to, int data) {

	// only if from and to index are within bounds
	if(from < 26 && to < 26 && from >=0 && to >= 0) {

		vertices[from][to] = data;

	} else {

		cout << "ERROR: Out of bounds" << endl;
	}

}

void AdjacencyMatrix::print() {

	// loop through the matrix and print
	for (int i = 0; i < 26; ++i) {

		for (int j = 0; j < 26; ++j) {

			if(vertices[i][j] < INT_MAX)
				cout << vertices[i][j] << "\t";
			else
				cout << "N/A"	<< "\t";

		}

		cout << endl;
	}	
}

void AdjacencyMatrix::dft(int start) {

	cout << "Depth first traveral for " << start << endl;

	// create an empty stack
	Stack stack;

	int current = start;

	// reinitialize the visited array
	initVisited();

	// mark the start vertex as visited
	visited[start] = true;

	// push the start vertex to stack
	stack.push(start);

	while(!stack.empty()) {

		current = stack.pop();

		printf("%c\n", current + 'a');

		for (int i = 0; i < 26; ++i)
		{
			// if the this city is within reach to this city and 
			// this city has not been visited yet

			if(vertices[current][i] < INT_MAX && !visited[i]) {

				visited[i] = true;
				stack.push(i);
			}
		}
	}
}

void AdjacencyMatrix::bft(int start) {

	cout << "Breadth first traveral for " << start << endl;

	// create an empty queue
	Queue queue;

	int current = start;

	// reinitialize the visited array
	initVisited();

	// mark the start vertex as visited
	visited[start] = true;

	// push the start vertex to stack
	queue.enqueue(start);

	while(!queue.empty()) {

		current = queue.dequeue();

		printf("%c\n", current + 'a');

		for (int i = 0; i < 26; ++i)
		{
			// if the this city is within reach
			if(vertices[current][i] < INT_MAX && !visited[i]) {

				visited[i] = true;
				queue.enqueue(i);
			}
		}
	}
}


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
	from = from - 'a';
	to = to - 'a';
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


	cout << endl << "Depth first traveral from : ";

	printf("%c\n", start);
	

	// calculating index from letter
	start = start - 'a';


	// create an empty frontier stack
	Stack frontier;

	int current = start;

	// reinitialize the visited array
	initVisited();

	// mark the start vertex as visited
	visited[start] = true;

	// push the start vertex to stack
	frontier.push(start);

	while(!frontier.empty()) {

		current = frontier.pop();

		printf("%c\t", current + 'a');

		for (int i = 0; i < 26; ++i) {
			// if the current city is within reach to this city and 
			// this city has not been visited yet

			if(vertices[current][i] < INT_MAX && !visited[i]) {

				visited[i] = true;

				frontier.push(i);
			}
		}
	}
	
	cout << endl;	
}

void AdjacencyMatrix::bft(int start) {

	cout << endl << "Breadth first traveral from : ";

	printf("%c\n", start);

	// calculating index from letter
	start = start - 'a';

	// create an empty frontier queue
	Queue frontier;

	int current = start;

	// reinitialize the visited array
	initVisited();

	// mark the start vertex as visited
	visited[start] = true;

	// push the start vertex to stack
	frontier.enqueue(start);

	while(!frontier.empty()) {

		current = frontier.dequeue();

		printf("%c\t", current + 'a');

		for (int i = 0; i < 26; ++i) {

			// if the this city is within reach
			if(vertices[current][i] < INT_MAX && !visited[i]) {

				visited[i] = true;

				frontier.enqueue(i);
			}
		}
	}

	cout << endl;
}

int AdjacencyMatrix::dfs(int source, int destination) {

	// calculating index from letter
	source = source - 'a';
	// destination = destination - 'a';

	int iterations = 0;

	// create an empty frontier stack
	Stack frontier;

	int current = source;

	// reinitialize the visited array
	initVisited();

	// mark the start vertex as visited
	visited[source] = true;

	// push the start vertex to stack
	frontier.push(source);

	while(!frontier.empty()) {

		current = frontier.pop();

		if(current == destination) break;

		for (int i = 0; i < 26; ++i) {
			// if the current city is within reach to this city and 
			// this city has not been visited yet

			if(vertices[current][i] < INT_MAX && !visited[i]) {

				visited[i] = true;

				frontier.push(i);
			}
		}

		iterations++;
	}	

	return iterations;
}

int AdjacencyMatrix::bfs(int source, int destination) {

	// calculating index from letter
	source = source - 'a';

	int iterations = 0;

	// create an empty frontier queue
	Queue frontier;

	int current = source;

	// reinitialize the visited array
	initVisited();

	// mark the start vertex as visited
	visited[source] = true;

	// push the start vertex to stack
	frontier.enqueue(source);

	while(!frontier.empty()) {

		current = frontier.dequeue();

		if(current == destination) break;

		for (int i = 0; i < 26; ++i) {

			// if the this city is within reach
			if(vertices[current][i] < INT_MAX && !visited[i]) {

				visited[i] = true;

				frontier.enqueue(i);
			}
		}

		iterations++;
	}

	return iterations;
}

int AdjacencyMatrix::uniform(int source, int destination) {

	// calculating index from letter
	source = source - 'a';

	int iterations = 0;

	// create an empty frontier queue
	Queue frontier;

	int current = source;
	int cost[26];
	// reinitialize the visited array
	initVisited();

	// mark the start vertex as visited
	visited[source] = true;

	// push the start vertex to stack
	frontier.enqueue(source);

	while(!frontier.empty()) {

		current = frontier.dequeue();

		if(current == destination) break;

		for (int i = 0; i < 26; ++i) {

			// if the this city is within reach
			if(vertices[current][i] < INT_MAX) {

				if(!visited[i]) {
					visited[i] = true;
					frontier.enqueue(i);
					cost[i] = vertices[current][i];
				} else {
					if(vertices[current][i] < cost[i]) {
						cost[i] = vertices[current][i];
					}
				}
			}
		}

		iterations++;
	}

	return iterations;
}
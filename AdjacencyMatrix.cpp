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
#include <algorithm>
#include <list>
#include <unordered_map>
#include "AdjacencyMatrix.h"
#include "Stack.h"
#include "Queue.h"
int hsld[26] = 	{
	366,
	0,
	160,
	242,
	161,
	176,
	77,
	151,
	226,
	INT_MAX,
	INT_MAX,
	244,
	241,
	234,
	380,
	100,
	INT_MAX,
	193,
	253,
	329,
	80,
	199,
	INT_MAX,
	INT_MAX,
	INT_MAX,
	374
};

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

	explored.clear();
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

int AdjacencyMatrix::countChildren(int node) {
	int count = 0;

	// count number of childrens
	for (int i = 0; i < 26; ++i)
		if(vertices[node][i] < INT_MAX) count ++;

	return count;
}

int* AdjacencyMatrix::getChildren(int node)
{
	int count = 0, counter = 0;

	count = countChildren(node);

	// create an array to hold all the childrens
	int* children = new int[count];

	for (int i = 0; i < 26; i++) {
		// if theres a path add this node to the children list
		if(vertices[node][i] < INT_MAX) {
			children[counter] = i;	
			counter++;
		} 

	}	

	return children;
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

void AdjacencyMatrix::DFT(int start) {


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

void AdjacencyMatrix::BFT(int start) {

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

int AdjacencyMatrix::DFS(int source, int destination) {

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

int AdjacencyMatrix::BFS(int source, int destination) {

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


int AdjacencyMatrix::UCS(int source, int destination) {

	// calculating index from letter
	source = source - 'a';

	// create an empty frontier queue, we will use it a priority queue by adding things at head
	Queue frontier;

	int current = source;

	int pathCost = 0;

	// reinitialize the visited array
	initVisited();

	cout << endl << "UCS Begins" << endl;
	// push the start vertex to stack
	frontier.enqueue(source, pathCost);
	cout << endl << "Queue" << endl;
	frontier.print();
	cout << endl;
	int counter = 0;
	while(!frontier.empty()) {

		pathCost = frontier.getHead()->getCost();

		current = frontier.dequeue();

		if(current == destination) break;

		// get all children in sorted order such that lowest cost is on top
		int count = countChildren(current);

		int* children = getChildren(current);

		for (int i = 0; i < count; ++i) {

			if(!explored[children[i]][pathCost + vertices[current][children[i]]]) {
				frontier.priority(children[i], pathCost + vertices[current][children[i]]);
				explored[children[i]][pathCost + vertices[current][children[i]]] = true;
			}

		}
		cout << "Queue" << endl;
		frontier.print();
		cout << endl;
	}

	return pathCost;
}

void AdjacencyMatrix::GBFS(int source, int destination) {

	// calculating index from letter
	source = source - 'a';

	// create an empty frontier queue, we will use it a priority queue by adding things at head
	Queue frontier;
	list<int> path;


	int current = source;

	int pathCost = 0;

	// reinitialize the visited array
	initVisited();

	cout << endl << "GBFS Begins" << endl;
	// push the start vertex to stack
	frontier.priority(source, hsld[source]);
	cout << endl << "Queue" << endl;
	frontier.print();
	cout << endl;
	int counter = 0;
	while(!frontier.empty()) {
		pathCost = hsld[frontier.getHead()->getValue()];
		current = frontier.dequeue();
		path.push_back(current);
		if(current == destination) break;

		// get all children in sorted order such that lowest cost is on top
		int count = countChildren(current);

		int* children = getChildren(current);

		for (int i = 0; i < count; ++i) {

			if(!explored[children[i]][hsld[children[i]]]) {
				frontier.priority(children[i], hsld[children[i]]);
				explored[children[i]][hsld[children[i]]] = true;
			}

		}
		cout << "Queue" << endl;
		frontier.print();
		cout << endl;
		counter++;
	}
	cout << endl << "Greedy Path:" << endl;
	for (list<int>::iterator it = path.begin(); it != path.end(); ++it)
	{
		printf("%c\n", *it + 'A');
	}
}

void AdjacencyMatrix::aStar(int source, int destination) {

	// calculating index from letter
	source = source - 'a';

	// create an empty frontier queue, we will use it a priority queue by adding things at head
	Queue frontier;
	
	unordered_map<int, unordered_map<int, int> > path;
	unordered_map<int, unordered_map<int, int> > parentCost;
	unordered_map<int, unordered_map<int, int> > pathCost;

	int current = source, currentC = 0;

	path[source][0] = source;
	parentCost[source][hsld[source]] = hsld[source];
	pathCost[source][hsld[source]] = 0;

	explored.clear();

	cout << endl << "AStar Begins" << endl;

	// push the start vertex to stack
	frontier.priority(source, pathCost[source][hsld[source]] + hsld[source]);

	cout << endl << "Queue" << endl;
	frontier.print();
	cout << endl;

	while(!frontier.empty()) {

		currentC = frontier.getHead()->getCost();
		current = frontier.dequeue();
		
		if(current == destination) break;
		// get all children 
		int count = countChildren(current);
		int* children = getChildren(current);

		for (int i = 0; i < count; ++i) {

			int cost = pathCost[current][currentC] + vertices[current][children[i]];
			if(!explored[children[i]][cost + hsld[children[i]]]) {
				pathCost[children[i]][cost+hsld[children[i]]] = cost;
				path[children[i]][cost+hsld[children[i]]] = current;
				parentCost[children[i]][cost+hsld[children[i]]] = currentC;
				frontier.priority(children[i], cost + hsld[children[i]]);
				explored[children[i]][cost+ hsld[children[i]]] = true;
			}

		}

		cout << "Queue" << endl;
		frontier.print();
		cout << endl;
		
	}

	cout << endl << "AStar Path:" << endl;
	int p = destination;	
	int temp;
	while(true) {
		printf("%c\n", p + 'A');
		if(p == source) break;		
		temp = p;
		p = path[temp][currentC];
		currentC = parentCost[temp][currentC];
	}	
}
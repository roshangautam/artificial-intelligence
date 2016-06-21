//
//  main.cpp
//  Graph
//
//  Created by Roshan Gautam on 06/20/16.
//  Copyright © 2016 Roshan Gautam. All rights reserved.
//


#include <iostream>
#include "AdjacencyMatrix.h"

using namespace std;


int main(int argc, char **argv) {

	AdjacencyMatrix graph;

	graph.addEdge(0, 19, 140);
	graph.addEdge(19, 0, 140);
	graph.addEdge(0, 20, 118);
	graph.addEdge(20, 0, 118);
	graph.addEdge(0, 25, 75);
	graph.addEdge(25, 0, 75);

	graph.addEdge(1, 6, 211);
	graph.addEdge(6, 1, 211);
	graph.addEdge(1, 7, 90);
	graph.addEdge(7, 1, 90);
	graph.addEdge(1, 16, 101);	
	graph.addEdge(16, 1, 101);	
	graph.addEdge(1, 21, 85);
	graph.addEdge(21, 1, 85);


	graph.addEdge(19, 15, 151);
	graph.addEdge(15, 19, 151);
	graph.addEdge(19, 6, 99);	
	graph.addEdge(6, 19, 99);	
	graph.addEdge(19, 18, 80);
	graph.addEdge(18, 19, 80);

	graph.print();
	int value;
	cout << endl << "Enter a city for DFS and BFS ( 0 - 25)";
	cin >> value;

	graph.dft(value);
	graph.bft(value);

	return 0;
} 
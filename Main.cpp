//
//  main.cpp
//  Graph
//
//  Created by Roshan Gautam on 06/20/'p'.
//  Copyright © 2016 Roshan Gautam. All rights reserved.
//


#include <iostream>
#include <iomanip>
#include <climits>
#include "AdjacencyMatrix.h"

using namespace std;


int main(int argc, char **argv) {

	AdjacencyMatrix graph;

	graph.addEdge('a', 's', 140);
	graph.addEdge('a', 't', 118);
	graph.addEdge('a', 'z', 75);

	graph.addEdge('b', 'f', 211);
	graph.addEdge('b', 'g', 90);
	graph.addEdge('b', 'p', 101);	
	graph.addEdge('b', 'u', 85);

	graph.addEdge('c', 'd', 120);
	graph.addEdge('c', 'p', 138);	
	graph.addEdge('c', 'r', 146);

	graph.addEdge('d', 'c', 120);	
	graph.addEdge('d', 'm', 75 );

	graph.addEdge('e', 'h', 86);

	graph.addEdge('f', 'b', 211);	
	graph.addEdge('f', 's', 99);

	graph.addEdge('g', 'b', 90);

	graph.addEdge('h', 'e', 86);
	graph.addEdge('h', 'u', 98);

	graph.addEdge('i', 'n', 87);
	graph.addEdge('i', 'v', 92);
	
	graph.addEdge('l', 'm', 70);
	graph.addEdge('l', 't', 111);

	graph.addEdge('m', 'd', 75);	
	graph.addEdge('m', 'l', 70);

	graph.addEdge('n', 'i', 87);

	graph.addEdge('o', 's', 151);
	graph.addEdge('o', 'z', 71);

	graph.addEdge('p', 'b', 101);	
	graph.addEdge('p', 'c', 138);
	graph.addEdge('p', 'r', 97);	

	graph.addEdge('r', 'c', 146);
	graph.addEdge('r', 'p', 97);
	graph.addEdge('r', 's', 80);

	graph.addEdge('s', 'a', 140);
	graph.addEdge('s', 'f', 99);		
	graph.addEdge('s', 'o', 151);	
	graph.addEdge('s', 'r', 80);		
	
	graph.addEdge('t', 'a', 118);
	graph.addEdge('t', 'l', 111);	

	graph.addEdge('u', 'b', 85);
	graph.addEdge('u', 'h', 98);	
	graph.addEdge('u', 'v', 142);

	graph.addEdge('v', 'i', 92);
	graph.addEdge('v', 'u', 142);

	graph.addEdge('z', 'a', 75);
	graph.addEdge('z', 'o', 71);

	// we are assuming 0 is a therefore 1 is b i.e. Bucharest
	cout << "A* From Arad to Bucharest " << endl;
	graph.aStar('a', 1);
	
	return 0;
} 
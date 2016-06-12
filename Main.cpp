//
//  main.cpp
//  tree
//
//  Created by Roshan Gautam on 5/31/16.
//  Copyright © 2016 Roshan Gautam. All rights reserved.
//


#include <iostream>
#include <fstream>
#include <cstdlib>

#include "BinarySearchTree.h"

using namespace std;

//Forward declarations for some common handy functions
void insert();
void search();
void load();
void generate();
void breadthFirstSearch();
void depthFirstSearch();

//Binary Tree Global object
BinarySearchTree *tree;

int main(int argc, char **argv) {
    
    char c; //menu input
    
    std::cout << "Binary Search Tree!\n";
    
    tree = new BinarySearchTree(); // create a new instance of BST
    
    load(); //load data from a file and build a binary tree
    
    // Menu Options
    while(true) {
        
        cout << "Select an option (1-5) OR press Q to quit" << endl;
        
        cout << "1. Insert Node" << endl;
        
        cout << "2. Search Node" << endl;
        
        cout << "3. Depth Fist Traversal - Preorder" << endl;
        cout << "4. Depth Fist Traversal - Inorder" << endl;
        cout << "5. Depth Fist Traversal - Postorder" << endl;
        
        cout << "6. Breadth Fist Traversal" << endl;

        cout << "7. Generate a tree with random numbers" << endl;
        cout << "8. Search a node using BFS" << endl;
        cout << "9. Search a node using DFS" << endl;

        cin >> c;
        
        switch (c) {
                
            case '1':
                
                insert();
                
                break;
                
            case '2':
                
                search();
                
                break;
                
            case '3':
                
                cout << "Depth First Traversal - Preorder" << endl;
                
                tree->dftIterativePreorder();
                
                break;
                
            case '4':
                
                cout << "Depth First Traversal - Inorder" << endl;
                
                tree->dftIterativeInorder();
                
                break;
                
            case '5':
                
                cout << "Depth First Traversal - Postorder" << endl;
                
                tree->dftIterativePostorder();
                
                break;
                
            case '6':
                
                cout << "Breadth First Traversal" << endl;
                
                tree->bft();
                
                break;

            case '7':
                
                cout << "Generating Tree with random Numbers:" << endl;
                
                generate();
                
                break; 

            case '8':
                
                breadthFirstSearch();
                
                break;  

            case '9':
                
                depthFirstSearch();
                
                break;                                                
                
            case 'Q':
            case 'q':
                
                cout << "Thats all folks" << endl;
                
                exit(0);
                
                break;
                
            default:
                
                break;
        }
    }
    
    return 0;
}

// Reads user input and inserts that onto global tree instance
void insert() {
    
    int data;
    
    cout << "Enter a value to insert:";
    
    cin >> data;
    
    if(tree->insert(data))
        cout << data << "Inserted successfully" << endl;
    else
        cout << "Insertion Failed" << endl;
    
}

// Reads user input and tries to find it in the tree
void search() {
    
    int data;
    
    cout << "Enter a value to search:";
    
    cin >> data;
    
    BSTNode *result = tree->search(data);
    
    if(result)
        
        cout << "Result: " << result->getValue() << endl;
    
    else
        
        cout << "No Results found" << endl;
}

// Load a list of data from a data file to tree
void load() {
    
    ifstream file("data.txt");
    
    if (file.is_open()) {
        
        int a;
        
        while(file >> a) {
            
            tree->insert(a);
        }
        
        cout << "Tree Generated from data file" << endl;
        
        file.close();
        
    } else {
        cout << "Can not open data file" << endl;
    }
}


//generate a tree with random numbers, ask the user to input the seed first
void generate() {

    int nodes, seed, start, end;

    cout << "Enter number of nodes to be generated:";
    cin >> nodes;

    cout << "Enter the seed value to generate random numbers:";
    cin >> seed;

    cout << "Enter the starting value of range:";
    cin >> start;

    cout << "Enter the ending value of range:";
    cin >> end;

    // set the seed to randomizer
    srand(seed);
    
    // create an empty binary search tree
    tree = new BinarySearchTree();

    for (int i = 0; i < nodes; ++i)
    {
        int num = (rand() % end) + start;
        tree->insert(num);
    }
    
}

void breadthFirstSearch() {
    int value;

    cout << "Enter the value to search:";
    cin >> value;

    tree->breadthFirstSearch(value);
}

void depthFirstSearch() {
    int value;

    cout << "Enter the value to search:";
    cin >> value;

    tree->depthFirstSearch(value);
}





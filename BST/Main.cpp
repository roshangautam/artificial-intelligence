//
//  main.cpp
//  tree
//
//  Created by Roshan Gautam on 5/31/16.
//  Copyright © 2016 Roshan Gautam. All rights reserved.
//


#include <iostream>
#include <fstream>
#include "BinarySearchTree.h"

using namespace std;

void insert();
void search();
void read();
void display();
void render(int*, char**);

BinarySearchTree *tree;


int main(int argc, char **argv) {
    
    char c;
    
    std::cout << "Binary Search Tree!\n";
    
    tree = new BinarySearchTree();
    read();
    
    while(true) {
        
        cout << "Select an option (1-5) OR press Q to quit" << "\n";
        
        cout << "1. Insert Node" << "\n";
        
        cout << "2. Search Node" << "\n";
        
        cout << "3. Depth Fist Traversal" << "\n";
        
        cout << "4. Breadth Fist Traversal" << "\n";
        
        cout << "5. Render Tree" << "\n";
        
        cin >> c;
        
        switch (c) {
                
            case '1':
                
                insert();
                
                break;
                
            case '2':
                
                search();
                
                break;
                
            case '3':
                
                cout << "Depth First Traversal" << "\n";
                
                tree->dftRecursivePostorder(tree->getRoot());
                
                break;
                
            case '4':
                
                tree->bft();
                
                break;
                
            case '5':
                
                render(&argc, argv);
                
                break;
                
            case 'Q':
            case 'q':
                
                cout << "Thats all folks" << "\n";
                
                exit(0);
                
                break;
                
            default:
                
                break;
        }
    }
    
    return 0;
}

void insert() {
    
    int data;
    
    cout << "Enter a value to insert:";
    
    cin >> data;
    
    if(tree->insert(data))
        cout << data << " inserted successfully" << "\n";
    else
        cout << "Insertion Failed" << "\n";
    
}

void search() {
    
    int data;
    
    cout << "Enter a value to search:";
    
    cin >> data;
    
    BSTNode *result = tree->search(data);
    
    if(result)
        
        cout << "Result: " << result->getData() << "\n";
    
    else
        
        cout << "No Results found" << "\n";
}


void read() {
    
    ifstream file("data.txt");
    
    if (file.is_open()) {
        
        int a;
        
        while(file >> a) {
            
            tree->insert(a);
        }
        
        cout << "Tree Generated from data file" << "\n";
        
        file.close();
        
    } else {
        cout << "Can not open data file" << "\n";
    }
}

void display() {
    glClearColor (0.0,0.0,0.0,1.0);
    glClear (GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0,10,-30);
    glColor3f(1,1,1);
    tree->draw(tree->getRoot(), 0, 0, 0);
    glutSwapBuffers();
}

void render(int *argc, char **argv) {
    glutInit(argc, argv);
    glutInitWindowSize(2880, 1800);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutCreateWindow("Binary Search Tree");
    glutReshapeFunc(tree->reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc (tree->keyboard);
    glClearColor(0,0,0,1);
    glDisable(GL_DEPTH_TEST);
    glutMainLoop();
}
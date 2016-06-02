//
//  Tree.h
//  BST
//
//  Created by Roshan Gautam on 6/1/16.
//  Copyright © 2016 Roshan Gautam. All rights reserved.
//

#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <string>
#include <math.h>
#include "Stack.h"
#include "Queue.h"

#endif /* BinarySearchTree_h */

class BinarySearchTree {

    BSTNode* root;
    
public:
    
    BinarySearchTree();
    BinarySearchTree(BSTNode* BSTNode);
    BSTNode* search(int data);
    BSTNode* getRoot();
    bool insert(int data);
    void dftRecursivePreorder(BSTNode* current);
    void dftRecursiveInorder(BSTNode* current);
    void dftRecursivePostorder(BSTNode* current);
    void dftIterative();
    void bft();
    
    //Graphics function
    static void reshape (int width, int height);
    void data(float x, float y, string text);
    static void keyboard(unsigned char key, int x, int y);
    void arc(float x1,float y1,float x2, float y2);
    void node(GLfloat x, GLfloat y, GLfloat radius);
    void draw(BSTNode* root, float x1, float y1, int level);
};



//
//  BinarySearchTree.cpp
//  BST
//
//  Created by Roshan Gautam on 5/31/16.
//  Copyright © 2016 Roshan Gautam. All rights reserved.
//

#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() {
    root = NULL;
}

BinarySearchTree::BinarySearchTree(BSTNode *BSTNode) {
    root = BSTNode;
}

BSTNode* BinarySearchTree::search(int data) {
    BSTNode *iterator = root;
    while(iterator != NULL && iterator->getData() != data) {
        if(data < iterator->getData()) {
            iterator = iterator->getLeft();
        } else {
            iterator = iterator->getRight();
        }
    }
    return iterator;
}

BSTNode* BinarySearchTree::getRoot() {
    return root;
}

bool BinarySearchTree::insert(int data) {
    
    BSTNode *node = new BSTNode(data);
    
    if(!node) return false;
    
    if(root == NULL)
        root = node;
    else {
        BSTNode *iterator = root;
        BSTNode *temp = iterator;
        
        while(iterator) {
            temp = iterator;
            if(data < temp->getData())
                iterator = iterator->getLeft();
            else
                iterator = iterator->getRight();
        }
        
        if(data < temp->getData())
            temp->setLeft(node);
        else
            temp->setRight(node);
    }
    
    return true;
}

void BinarySearchTree::dftRecursiveInorder(BSTNode *current) {
    
    if(current == NULL) return;
    dftRecursiveInorder(current->getLeft());
    cout << current << "\n";
    dftRecursiveInorder(current->getRight());
}

void BinarySearchTree::dftRecursivePreorder(BSTNode *current) {
    
    if(current == NULL) return;
    cout << current << "\n";
    dftRecursivePreorder(current->getLeft());
    dftRecursivePreorder(current->getRight());
}

void BinarySearchTree::dftRecursivePostorder(BSTNode *current) {
    
    if(current == NULL) return;
    dftRecursivePostorder(current->getLeft());
    dftRecursivePostorder(current->getRight());
    cout << current << "\n";    
}

void BinarySearchTree::dftIterative() {
    
    BSTNode *node = root;
    
    Stack stack;
    
    while(!stack.empty() || node != NULL) {
        
        if(node != NULL) {
            
            stack.push(node);
            
            node = node->getLeft();
            
        } else {
            
            cout << stack.pop() << "\n";
            
            node = node->getRight();
        }
    }
}

void BinarySearchTree::bft() {
    
    BSTNode *node = root;
    
    Queue queue;
    
    queue.enqueue(node);
    
    while (!queue.empty()) {
        
        cout << queue.dequeue() << "\n";
        
        if (node->getLeft() != NULL) {
            
            queue.enqueue(node->getLeft());
            
        }
        
        if (node->getRight() != NULL) {
            
            queue.enqueue(node->getRight());
            
        }
    }
}

//Graphical Tree Functions

void BinarySearchTree::reshape (int width, int height) {
    glViewport (0, 0, (GLsizei)width, (GLsizei)height);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective (60, (GLfloat)width / (GLfloat)height, 0.1, 100.0);
    glMatrixMode (GL_MODELVIEW);
}


void BinarySearchTree::keyboard(unsigned char key, int x, int y)
{
    switch (key) {
        case 27:
            exit(0);
            break;
    }
}

void BinarySearchTree::node(GLfloat x, GLfloat y, GLfloat radius){
    int i;
    int polyCount = 25; //# of triangles used to draw circle
    GLfloat twoPi = 2.0f * M_PI;
    glBegin(GL_POLYGON);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= polyCount;i++) {
        glVertex2f(x + (radius * cos(i *  twoPi / polyCount)), y + (radius * sin(i * twoPi / polyCount)));
    }
    glEnd();
}

void BinarySearchTree::arc(float x1,float y1,float x2, float y2) {
    glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glEnd();
}

void BinarySearchTree::data(float x, float y, string text) {
    GLvoid *font_style = GLUT_BITMAP_HELVETICA_18;
    glColor3f(1, 0, 0);
    glRasterPos3f(x-0.4, y-0.2, 0);
    for (int i = 0; text[i] != '\0'; i++){
        glutBitmapCharacter(font_style, text[i]);
    }
    glColor3f(1, 1, 1);
}

void BinarySearchTree::draw(BSTNode* root,float x1,float y1,int level) {
    if (root==NULL) return;
    float radius = 1.0;
    float left_angle = 245;
    float right_angle = 115;
    float branch_length = 12 - level*2.5;
    float angle_change = 20;
    
    if(root->getLeft()) {
        // Draw the Left circle
        float angle = left_angle - level*angle_change;
        double radian = angle*3.14/180;
        float x2 = x1 + branch_length * sin((double) radian);
        float y2 = y1 + branch_length * cos((double) radian);
        arc(x1,y1,x2,y2);
        draw(root->getLeft(),x2,y2,level+1);
    }
    if(root->getRight()) {
        // Draw the Right circle
        float angle = right_angle + level*angle_change;
        float radian = angle*3.14/180;
        float x2 = x1 + branch_length * sin((double) radian);
        float y2 = y1 + branch_length * cos((double) radian);
        arc(x1,y1,x2,y2);
        draw(root->getRight(),x2,y2,level+1);
    }
    node(x1,y1,radius);
    data(x1,y1, to_string(root->getData()));
}
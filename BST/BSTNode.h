//
//  Node.h
//  BST
//
//  Created by Roshan Gautam on 5/31/16.
//  Copyright © 2016 Roshan Gautam. All rights reserved.
//

#ifndef BSTNode_h
#define BSTNode_h

#include <iostream>

#endif /* BSTNode_h */

using namespace std;

class BSTNode {
    
    int _value; // actual node value
    BSTNode* _left; // left pointer
    BSTNode* _right; // right pointer
    
public:
    
    BSTNode(); //default constructor
    BSTNode(int value); // intializer constructor
    int getValue(); // return node value
    void setValue(int value); // set node value
    void setLeft(BSTNode* left); // set left pointer
    void setRight(BSTNode* right); // set right pointer
    BSTNode* getLeft(); // get left pointer
    BSTNode* getRight(); // get right pointer
    friend ostream& operator<<(ostream& os, BSTNode* node); // overloading cout for easy printing
};
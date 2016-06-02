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
    
    int data;
    BSTNode* left;
    BSTNode* right;
    
public:
    
    BSTNode();
    BSTNode(int value);
    int getData();
    void setData(int value);
    void setLeft(BSTNode* node);
    void setRight(BSTNode* node);
    BSTNode* getLeft();
    BSTNode* getRight();
    friend ostream& operator<<(ostream& os, BSTNode* node);
};
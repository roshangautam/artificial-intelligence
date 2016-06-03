//
//  Tree.h
//  BST
//
//  Created by Roshan Gautam on 6/1/16.
//  Copyright © 2016 Roshan Gautam. All rights reserved.
//

#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include <string>
#include <math.h>
#include "Stack.h"
#include "Queue.h"

#endif /* BinarySearchTree_h */

class BinarySearchTree {

    BSTNode* _root;
    
public:
    
    BinarySearchTree();
    BinarySearchTree(BSTNode* root);
    BSTNode* search(int value);
    BSTNode* getRoot();
    bool insert(int value);
    void dftRecursivePreorder(BSTNode* node);
    void dftRecursiveInorder(BSTNode* node);
    void dftRecursivePostorder(BSTNode* node);
    void dftIterativePreorder();
    void dftIterativeInorder();
    void dftIterativePostorder();
    void bft();
};



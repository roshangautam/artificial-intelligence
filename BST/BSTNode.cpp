//
//  BSTNode.cpp
//  BST
//
//  Created by Roshan Gautam on 6/1/16.
//  Copyright © 2016 Roshan Gautam. All rights reserved.
//

#include "BSTNode.h"


BSTNode::BSTNode() {
    data = 0;
    left = NULL;
    right = NULL;
}

BSTNode::BSTNode(int value) {
    data = value;
    left = NULL;
    right = NULL;
}

int BSTNode::getData() {
    return data;
}

void BSTNode::setData(int value) {
    data = value;
}

void BSTNode::setLeft(BSTNode* BSTNode) {
    left = BSTNode;
}

void BSTNode::setRight(BSTNode* BSTNode) {
    right = BSTNode;
}

BSTNode* BSTNode::getLeft() {
    return left;
}

BSTNode* BSTNode::getRight() {
    return right;
}

ostream& operator<<(ostream& os, BSTNode* node) {
    if(node) {
        if(node->getLeft())
            cout << node->getLeft()->getData() << " <-- ";
        else
            cout << "NULL " << " <-- ";
        
        os << node->getData() ;
        
        if(node->getLeft())
            cout << " --> " << node->getRight()->getData() ;
        else
            cout  << " --> " << "NULL" << " ";
    } else
        os << "Empty BSTNode" << "\n";
    return os;
}

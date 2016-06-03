//
//  BSTNode.cpp
//  BST
//
//  Created by Roshan Gautam on 6/1/16.
//  Copy_right © 2016 Roshan Gautam. All _rights reserved.
//

#include "BSTNode.h"

// Default Constructor - initialize everything to zero
BSTNode::BSTNode() {
    _value = 0;
    _left = NULL;
    _right = NULL;
}

// Initializer Constructor - initialize value
BSTNode::BSTNode(int value) {
    _value = value;
    _left = NULL;
    _right = NULL;
}

int BSTNode::getValue() {
    return _value;
}

void BSTNode::setValue(int value) {
    _value = value;
}

void BSTNode::setLeft(BSTNode* left) {
    _left = left;
}

void BSTNode::setRight(BSTNode* right) {
    _right = right;
}

BSTNode* BSTNode::getLeft() {
    return _left;
}

BSTNode* BSTNode::getRight() {
    return _right;
}

ostream& operator<<(ostream& os, BSTNode* node) {
    if(node) {
//        if(node->getLeft())
//            cout << node->getLeft()->getValue() << " <-- ";
//        else
//            cout << "NULL " << " <-- ";
        
        os << node->getValue() ;
        
//        if(node->getLeft())
//            cout << " --> " << node->getRight()->getValue() ;
//        else
//            cout  << " --> " << "NULL" << " ";
    } else
        os << "Empty BSTNode" << "\n";
    return os;
}

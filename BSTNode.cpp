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
    // returns informational content, integer value
    return _value;
}

void BSTNode::setValue(int value) {
    // sets informational content
    _value = value;
}

void BSTNode::setLeft(BSTNode* left) {
    // sets left point
    _left = left;
}

void BSTNode::setRight(BSTNode* right) {
    // sets right pointer 
    _right = right;
}

BSTNode* BSTNode::getLeft() {
    // returns left pointer
    return _left;
}

BSTNode* BSTNode::getRight() {
    // returns right pointer
    return _right;
}

ostream& operator<<(ostream& os, BSTNode* node) {
    // operator overloading to easily cout a node, formatted printing commented out
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

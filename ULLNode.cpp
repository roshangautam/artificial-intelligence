//
//  ULLNode.cpp
//  BST
//
//  Created by Roshan Gautam on 6/1/16.
//  Copyright © 2016 Roshan Gautam. All rights reserved.
//

#include "ULLNode.h"

ULLNode::ULLNode() {
    //Default Constructor, initialize everything to 0
    _value = 0;
    _next = NULL;
    _previous = NULL;
}

ULLNode::ULLNode(int value) {
    // Constructor to create a ULLNode with given int as informational content
    _value = value;
    _next = NULL;
    _cost = 0;
}

ULLNode::ULLNode(int value, int cost) {
    // Constructor to create a ULLNode with given int as informational content
    _value = value;
    _next = NULL;
    _cost = cost;
}

int ULLNode::getValue() {
    // returns informational content of this node
    return _value;
}

int ULLNode::getCost() {
    // returns informational content of this node
    return _cost;
}

void ULLNode::setValue(int value) {
    // set informational content of this node
    _value = value;
}

void ULLNode::setValue(int value, int cost) {
    // set informational content of this node
    _value = value;
    _cost = cost;
}

ULLNode* ULLNode::getNext() {
    // returns structural content of this node , next pointer
    return _next;
}

void ULLNode::setNext(ULLNode *next) {
    // set structural content of this node , next pointer
    _next = next;
}

ULLNode* ULLNode::getPrevious() {
    // returns structural content of this node , previous pointer
    return _previous;
}

void ULLNode::setPrevious(ULLNode *previous) {
    // set structural content of this node , previous pointer
    _previous = previous;
}

void ULLNode::clearNode() {
    // Clear all values of current node.
    _next = NULL;
    _value = 0;
    _previous = NULL;
}

ostream& operator<<(ostream& os, ULLNode* node) {
    // operator overloading to easily cout a node
    if(node) {
        os << node->getValue();
    } else
        os << "Empty ULLNode" << "\n";
    return os;
}
//
//  ULLNode.cpp
//  BST
//
//  Created by Roshan Gautam on 6/1/16.
//  Copyright © 2016 Roshan Gautam. All rights reserved.
//

#include "ULLNode.h"

ULLNode::ULLNode() {
    _value = NULL;
    _next = NULL;
}

ULLNode::ULLNode(BSTNode* value) {
    _value = value;
    _next = NULL;
}

BSTNode* ULLNode::getValue() {
    return _value;
}

void ULLNode::setValue(BSTNode *value) {
    _value = value;
}

ULLNode* ULLNode::getNext() {
    return _next;
}

void ULLNode::setNext(ULLNode *next) {
    _next = next;
}

ULLNode* ULLNode::getPrevious() {
    return _previous;
}

void ULLNode::setPrevious(ULLNode *previous) {
    _previous = previous;
}

void ULLNode::clearNode() {
    _next = NULL;
    _value = NULL;
    _previous = NULL;
}

ostream& operator<<(ostream& os, ULLNode* node) {
    if(node) {
        os << node->getValue()->getValue();
    } else
        os << "Empty ULLNode" << "\n";
    return os;
}
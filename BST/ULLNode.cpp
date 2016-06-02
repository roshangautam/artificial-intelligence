//
//  ULLNode.cpp
//  BST
//
//  Created by Roshan Gautam on 6/1/16.
//  Copyright © 2016 Roshan Gautam. All rights reserved.
//

#include "ULLNode.h"

ULLNode::ULLNode() {
    data = NULL;
    next = NULL;
}

ULLNode::ULLNode(BSTNode* value) {
    data = value;
    next = NULL;
}

BSTNode* ULLNode::getData() {
    return data;
}

void ULLNode::setData(BSTNode *value) {
    data = value;
}

ULLNode* ULLNode::getNext() {
    return next;
}

void ULLNode::setNext(ULLNode *node) {
    next = node;
}

void ULLNode::clearNode() {
    next = NULL;
    data = NULL;
}

ostream& operator<<(ostream& os, ULLNode* node) {
    if(node) {
        os << node->getData()->getData();
    } else
        os << "Empty ULLNode" << "\n";
    return os;
}
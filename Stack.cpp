//
//  Stack.cpp
//  BST
//
//  Created by Roshan Gautam on 6/2/16.
//  Copyright © 2016 Roshan Gautam. All rights reserved.
//

#include "Stack.h"


Stack::Stack() {
    UnorderedLinkedList();
}

void Stack::push(BSTNode *node) {
    addAtHead(node);
}

BSTNode* Stack::pop() {
    BSTNode* top = getHead()->getValue();
    removeFromHead(top);
    return top;
}

BSTNode* Stack::peek() {
    BSTNode* top = getHead()->getValue();
    return top;
}
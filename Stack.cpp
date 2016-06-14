//
//  Stack.cpp
//  BST
//
//  Created by Roshan Gautam on 6/2/16.
//  Copyright © 2016 Roshan Gautam. All rights reserved.
//

#include "Stack.h"


Stack::Stack() {
    // cout << "Stack Initialized" << endl;
}

void Stack::push(BSTNode *node) {
	//add to the head of the list
    addAtHead(node);
}

BSTNode* Stack::pop() {
	// remove from head of the list
    BSTNode* top = getHead()->getValue();
    removeFromHead(top);
    return top;
}

BSTNode* Stack::peek() {
	// take a peek on the top of the list
    BSTNode* top = getHead()->getValue();
    return top;
}
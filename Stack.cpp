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

void Stack::push(int value) {
	//add to the head of the list
    addAtHead(value);
}

int Stack::pop() {
	// remove from head of the list
    int top = getHead()->getValue();
    removeFromHead(top);
    return top;
}

int Stack::peek() {
	// take a peek on the top of the list
    int top = getHead()->getValue();
    return top;
}
//
//  Queue.cpp
//  BST
//
//  Created by Roshan Gautam on 6/2/16.
//  Copyright © 2016 Roshan Gautam. All rights reserved.
//

#include "Queue.h"

Queue::Queue() {
    cout << "Queue Initialized" << endl;
}

void Queue::enqueue(BSTNode *node) {
	// add at the tail of the list
    addAtTail(node);
}

BSTNode* Queue::dequeue() {
	// remove from the head of the list
    BSTNode* top = NULL;
    removeFromHead(top);
    return top;
}

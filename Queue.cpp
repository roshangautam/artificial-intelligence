//
//  Queue.cpp
//  BST
//
//  Created by Roshan Gautam on 6/2/16.
//  Copyright © 2016 Roshan Gautam. All rights reserved.
//

#include "Queue.h"

Queue::Queue() {
    // cout << "Queue Initialized" << endl;
}

void Queue::priority(int data) {
	// add at the head of the list
    addAtHead(data);
}

void Queue::priority(int data, int cost) {
	// add at the head of the list
    addAtHead(data, cost);
}

void Queue::enqueue(int data) {
	// add at the tail of the list
    addAtTail(data);
}

void Queue::enqueue(int data, int cost) {
	// add at the tail of the list
    addAtTail(data,cost);
}

int Queue::dequeue() {
	// remove from the head of the list
    int top = getHead()->getValue();
    removeFromHead(top);
    return top;
}

void Queue::print() {
    ULLNode* current = getHead();
    while(current) {
        printf("City:%c, Cost:%d\n", current->getValue() + 'A', current->getCost());
        
        current = current->getNext();
    }
}

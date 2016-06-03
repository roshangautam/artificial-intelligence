//
//  Queue.cpp
//  BST
//
//  Created by Roshan Gautam on 6/2/16.
//  Copyright © 2016 Roshan Gautam. All rights reserved.
//

#include "Queue.h"

Queue::Queue() {
    UnorderedLinkedList();
}

void Queue::enqueue(BSTNode *node) {
    addAtTail(node);
}

BSTNode* Queue::dequeue() {
    BSTNode* top = getHead()->getValue();
    removeFromHead(top);
    return top;
}

//
//  Queue.hpp
//  BST
//
//  Created by Roshan Gautam on 6/2/16.
//  Copyright © 2016 Roshan Gautam. All rights reserved.
//

#ifndef Queue_h
#define Queue_h
#include <iostream>
#include "UnorderedLinkedList.h"
#endif /* Queue_h */

// Inherits UnorderedLinkedList
class Queue : public UnorderedLinkedList {
public:
    Queue();
    void enqueue(BSTNode*);
    BSTNode* dequeue();
};
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
    void priority(int);
    void priority(int, int);
    void enqueue(int);
    void enqueue(int, int);
    int dequeue();
    void print();
};
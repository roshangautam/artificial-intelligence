//
//  UnorderedLinkedList.hpp
//  BST
//
//  Created by Roshan Gautam on 6/1/16.
//  Copyright © 2016 Roshan Gautam. All rights reserved.
//

#pragma once

#ifndef UnorderedLinkedList_h
#define UnorderedLinkedList_h

#include <iostream>
#include "ULLNode.h"

#endif /* UnorderedLinkedList_h */


class UnorderedLinkedList {
    ULLNode* _head; // structural content, points to the head of the list
    ULLNode* _tail; // structural content, points to the tail of the list
    bool addAtHead(ULLNode*);
    bool addAtHeadWithPriority(ULLNode*);
    bool addAtTail(ULLNode*);

public:
    UnorderedLinkedList();
    ULLNode* getHead();
    ULLNode* getTail();
    bool addAtHead(int value);
    bool addAtHead(int value, int cost);
    bool addAtTail(int value);
    bool addAtTail(int value, int cost);
    bool removeFromHead(int& node);
    bool removeFromTail(int& node);
    bool empty();
};
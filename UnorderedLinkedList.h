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
public:
    UnorderedLinkedList();
    ULLNode* getHead();
    ULLNode* getTail();
    bool addAtHead(BSTNode* value);
    bool addAtTail(BSTNode* value);
    bool removeFromHead(BSTNode*& node);
    bool removeFromTail(BSTNode*& node);
    bool empty();
};
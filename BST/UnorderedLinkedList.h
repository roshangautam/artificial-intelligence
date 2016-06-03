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
    ULLNode* _head;
    ULLNode* _tail;
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
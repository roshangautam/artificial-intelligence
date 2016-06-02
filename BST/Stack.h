//
//  Stack.hpp
//  BST
//
//  Created by Roshan Gautam on 6/2/16.
//  Copyright © 2016 Roshan Gautam. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include <iostream>
#include "UnorderedLinkedList.h"

#endif /* Stack_h */


class Stack : public UnorderedLinkedList {
public:
    Stack();
    void push(BSTNode*);
    BSTNode* pop();
};

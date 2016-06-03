//
//  ULLNode.hpp
//  BST
//
//  Created by Roshan Gautam on 6/1/16.
//  Copyright © 2016 Roshan Gautam. All rights reserved.
//

#ifndef ULLNode_hpp
#define ULLNode_hpp

#include <iostream>
#include "BSTNode.h"

#endif /* ULLNode_h */

class ULLNode {
    BSTNode* _value;
    ULLNode* _next;
    ULLNode* _previous;
public:
    ULLNode();
    ULLNode(BSTNode* value);
    void setValue(BSTNode* value);
    BSTNode* getValue();
    void setNext(ULLNode* next);
    ULLNode* getNext();
    void setPrevious(ULLNode* previous);
    ULLNode* getPrevious();
    void clearNode();
    friend ostream& operator<<(ostream& os, ULLNode* node);
};
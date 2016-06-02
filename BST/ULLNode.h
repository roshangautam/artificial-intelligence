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
    BSTNode* data;
    ULLNode* next;
public:
    ULLNode();
    ULLNode(BSTNode* data);
    void setData(BSTNode* data);
    BSTNode* getData();
    void setNext(ULLNode* node);
    ULLNode* getNext();
    void clearNode();
    friend ostream& operator<<(ostream& os, ULLNode* node);
};
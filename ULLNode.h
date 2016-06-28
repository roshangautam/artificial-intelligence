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

#endif /* ULLNode_h */

using namespace std;

class ULLNode {
    int _value; // informational content
    int _cost; // total distance to get to this city
    ULLNode* _next; // structural content
    ULLNode* _previous; //structural content, this one makes the list a doubly linked list
public:
    ULLNode();
    ULLNode(int value);
    ULLNode(int value, int cost);
    void setValue(int value);
    void setValue(int value, int cost);
    int getValue();
    int getCost();
    void setNext(ULLNode* next);
    ULLNode* getNext();
    void setPrevious(ULLNode* previous);
    ULLNode* getPrevious();
    void clearNode();
    friend ostream& operator<<(ostream& os, ULLNode* node);
};
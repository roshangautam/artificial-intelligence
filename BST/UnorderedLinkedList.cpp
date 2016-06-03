//
//  UnorderedLinkedList.cpp
//  BST
//
//  Created by Roshan Gautam on 6/1/16.
//  Copyright © 2016 Roshan Gautam. All rights reserved.
//

#include "UnorderedLinkedList.h"

UnorderedLinkedList::UnorderedLinkedList() {
    _head = NULL;
    _tail = NULL;
}

ULLNode* UnorderedLinkedList::getHead() {
    return _head;
}

ULLNode* UnorderedLinkedList::getTail() {
    return _tail;
}

bool UnorderedLinkedList::addAtHead(BSTNode *value) {
    
    bool success = true;
    
    ULLNode *newHead = new ULLNode(value);
    
    if(newHead) {
        
        if(_head == NULL) {
            _tail = newHead;
        }
        
        else {
            _head->setPrevious(newHead);
            newHead->setNext(_head);
        }
        
        _head = newHead;
        
    } else {
        
        success = false;
        
    }
    
    return success;
}

bool UnorderedLinkedList::addAtTail(BSTNode *node) {
    
    bool success = true;
    
    ULLNode *newNode = new ULLNode(node);
    
    if(newNode) {
        
        if(_head == NULL) _head = _tail = newNode;
        
        else {
            
            newNode->setPrevious(_tail);
            
            _tail->setNext(newNode);
            
            
            _tail = newNode;
            
        }
        
    } else {
        
        success = false;
        
    }
    
    return success;
}

bool UnorderedLinkedList::removeFromHead(BSTNode*& node) {
    
    bool success = true;
    
    ULLNode* toBeDeleted = _head;
    
    if(toBeDeleted == NULL) {
        
        cout << "Empty List" << endl;
        
        success = false;
        
    } else {
        
        node = toBeDeleted->getValue();
        
        _head = toBeDeleted->getNext();
        
        if(_head == NULL) _tail = NULL;
        
        toBeDeleted->clearNode();
        
        delete toBeDeleted;
    }
    
    return success;
}

bool UnorderedLinkedList::removeFromTail(BSTNode *&node) {
    bool success = true;
    
    ULLNode* toBeDeleted = _tail;
    
    if(toBeDeleted == NULL) {
        
        cout << "Empty List" << endl;
        
        success = false;
        
    } else {
        
        node = toBeDeleted->getValue();
        
        _tail = toBeDeleted->getPrevious();
        
        if(_tail == NULL) _head = NULL;
        
        toBeDeleted->clearNode();
        
        delete toBeDeleted;
    }
    
    return success;
}

bool UnorderedLinkedList::empty() {
    return _head == NULL;
}
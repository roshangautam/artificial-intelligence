//
//  UnorderedLinkedList.cpp
//  BST
//
//  Created by Roshan Gautam on 6/1/16.
//  Copyright © 2016 Roshan Gautam. All rights reserved.
//

#include "UnorderedLinkedList.h"

UnorderedLinkedList::UnorderedLinkedList() {
    //Default Constructor, initialize everything to 0
    _head = NULL;
    _tail = NULL;
}

ULLNode* UnorderedLinkedList::getHead() {
    // returns structural content of this node , head pointer
    return _head;
}

ULLNode* UnorderedLinkedList::getTail() {
    // returns structural content of this node , tail pointer
    return _tail;
}

bool UnorderedLinkedList::addAtHead(BSTNode* value) {
    // Add informational content, BSTNode* to the head of this list

    // Assume everything will work out fine
    bool success = true;
    
    //Create a new ULLNode
    ULLNode *newHead = new ULLNode(value);
    
    // If a new ULLNode was created
    if(newHead) {
        
        if(_head == NULL) _tail = newHead; // if list is empty, make the newly created ULLNode its tail
        else { // list is not empty

            _head->setPrevious(newHead); // for doubly linked list set the newly created ULLNode as the previous Node of current head
            newHead->setNext(_head); // set the current head as the next node to newly created ULLNode
        }

        // Set the newly created ULL node as the head of this list
        _head = newHead;
        
    } else {
        // Failed to create a new ULLNode
        success = false;
        
    }
    
    return success;
}

bool UnorderedLinkedList::addAtTail(BSTNode *node) {
    // Add informational content, BSTNode* to the tail of this list

    // Assume everything will work out fine
    bool success = true;
    
    //Create a new ULLNode
    ULLNode *newNode = new ULLNode(node);
    
    // If a new ULLNode was created
    if(newNode) {
        
        if(_head == NULL) _head = _tail = newNode; // if list is empty, make the newly created ULLNode its head and tail both
        else {
            
            newNode->setPrevious(_tail); // set the current tail as the previous node to newly created ULLNode 
            
            _tail->setNext(newNode); // set the newly created ULLNode as the next node of current tail
            
            _tail = newNode; // make the newly created ULLNode tail of this list
            
        }
        
    } else {
        // Failed to create a new ULLNode
        success = false;
        
    }
    
    return success;
}

bool UnorderedLinkedList::removeFromHead(BSTNode*& node) {
    // Removes a node from the top of the list

    // Assume everything will work out fine
    bool success = true;
    
    // Fetch the head of this list
    ULLNode* toBeDeleted = _head;
    
    if(toBeDeleted == NULL) {
        // List is empty as theres no head
        cout << "Empty List" << endl;
        
        success = false;
        
    } else { // List is not empty, proceed
        
        // set the informational content to pass by reference parameter to return is to calling environment
        node = toBeDeleted->getValue();
        
        // set the next pointer of current head as new head
        _head = toBeDeleted->getNext();
        
        // if new head is null also set tail as null
        if(_head == NULL) _tail = NULL;
        
        // clear the node 
        toBeDeleted->clearNode();
        
        // release the node from memory
        delete toBeDeleted;
    }
    
    return success;
}

bool UnorderedLinkedList::removeFromTail(BSTNode *&node) {
    // Removes a node from the tail of the list, this method uses the previous pointer, which is a property of doubly linked list

    // Assume everything will work out fine
    bool success = true;
    
    // Fetch the tail of this list
    ULLNode* toBeDeleted = _tail;
    
    if(toBeDeleted == NULL) {
        // List is empty as theres no tail 
        cout << "Empty List" << endl;
        
        success = false;
        
    } else {
        // set the informational content to pass by reference parameter to return is to calling environment
        node = toBeDeleted->getValue();

        // set the previous pointer of current tail as new tail
        _tail = toBeDeleted->getPrevious();

        // if new tail is null also set head as null
        if(_tail == NULL) _head = NULL;
        
        // clear the node 
        toBeDeleted->clearNode();
        
        // release the node from memory
        delete toBeDeleted;
    }
    
    return success;
}

bool UnorderedLinkedList::empty() {
    // check if the list is empty
    return _head == NULL; // if head is null return true else false
}
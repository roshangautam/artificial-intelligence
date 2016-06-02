//
//  UnorderedLinkedList.cpp
//  BST
//
//  Created by Roshan Gautam on 6/1/16.
//  Copyright © 2016 Roshan Gautam. All rights reserved.
//

#include "UnorderedLinkedList.h"

UnorderedLinkedList::UnorderedLinkedList() {
    head = NULL;
    tail = NULL;
}

ULLNode* UnorderedLinkedList::getHead() {
    return head;
}

ULLNode* UnorderedLinkedList::getTail() {
    return tail;
}

bool UnorderedLinkedList::addAtHead(BSTNode *node) {
    bool success = true;
    ULLNode *newHead = new ULLNode(node);
    if(newHead) {
        if(head == NULL) tail = newHead;
        else newHead->setNext(head);
        head = newHead;
    } else {
        success = false;
    }
    return success;
}

bool UnorderedLinkedList::addAtTail(BSTNode *node) {
    bool success = true;
    ULLNode *newNode = new ULLNode(node);
    if(newNode) {
        if(head == NULL) head = tail = newNode;
        else {
            tail->setNext(newNode);
            tail = newNode;
        }
    } else {
        success = false;
    }
    return success;
}

bool UnorderedLinkedList::removeFromHead(BSTNode*& node) {
    bool success = true;
    ULLNode* toBeDeleted = head;
    if(toBeDeleted == NULL) {
        cout << "Empty List" << endl;
        success = false;
    } else {
        node = toBeDeleted->getData();
        head = toBeDeleted->getNext();
        if(head == NULL) tail = NULL;
        toBeDeleted->clearNode();
        delete toBeDeleted;
    }
    return success;
}

bool UnorderedLinkedList::removeFromTail(BSTNode *&node) {
    bool success = true;
    
    return success;
}

bool UnorderedLinkedList::empty() {
    return head == NULL;
}
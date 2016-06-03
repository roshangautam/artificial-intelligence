//
//  BinarySearchTree.cpp
//  BST
//
//  Created by Roshan Gautam on 5/31/16.
//  Copyright © 2016 Roshan Gautam. All rights reserved.
//

#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() {
    _root = NULL;
}

BinarySearchTree::BinarySearchTree(BSTNode *root) {
    _root = root;
}

BSTNode* BinarySearchTree::search(int value) {
    
    BSTNode *found = _root;
    
    while(found != NULL && found->getValue() != value) {
        
        if(value < found->getValue()) {
            
            found = found->getLeft();
            
        } else {
            
            found = found->getRight();
        }
    }
    
    return found;
}

BSTNode* BinarySearchTree::getRoot() {
    return _root;
}

bool BinarySearchTree::insert(int value) {
    
    BSTNode* node = new BSTNode(value);
    BSTNode* iterator = NULL;
    BSTNode* temp = NULL;
    
    if(!node) return false;
    
    if(_root == NULL)
        _root = node;
    else {
        
        iterator = _root;
        temp = iterator;
        
        while(iterator) {
            temp = iterator;
            if(value < temp->getValue())
                iterator = iterator->getLeft();
            else
                iterator = iterator->getRight();
        }
        
        if(value < temp->getValue())
            temp->setLeft(node);
        else
            temp->setRight(node);
    }
    
    return true;
}

void BinarySearchTree::dftIterativeInorder() {
    
    BSTNode* node = _root;
    Stack* stack = new Stack();

    while(!stack->empty() || node != NULL) {
        
        if(node != NULL) {
            
            stack->push(node);
            
            node = node->getLeft();
            
        } else {
            
            node = stack->peek();
            
            cout << stack->pop() << endl;
            
            node = node->getRight();
        }
    }
}

void BinarySearchTree::dftIterativePreorder() {
    
    BSTNode* node = _root;

    if(node == NULL) return;
    
    Stack* stack = new Stack();
    
    stack->push(node);
    
    while(!stack->empty()) {
        
        node = stack->peek();
        
        cout << node << endl;
        stack->pop();
        if(node->getRight() != NULL) stack->push(node->getRight());
        if(node->getLeft() != NULL) stack->push(node->getLeft());
        
    }
}

void BinarySearchTree::dftIterativePostorder() {
    
    BSTNode* node = _root;
    Stack* stack = new Stack();
    BSTNode* lastVisitedNode = NULL;
    
    while(!stack->empty() || node != NULL) {
        
        if(node != NULL) {
            
            stack->push(node);
            
            node = node->getLeft();
            
        } else {
            
            BSTNode* peekNode = stack->peek();
            
            if(peekNode->getRight() != NULL && lastVisitedNode != peekNode->getRight())
                
                node = peekNode->getRight();
            
            else {
                
                cout << peekNode << endl;
                
                lastVisitedNode = stack->pop();
            }
        }
    }
}

void BinarySearchTree::dftRecursiveInorder(BSTNode *current) {
    
    if(current == NULL) return;
    dftRecursiveInorder(current->getLeft());
    cout << current << endl;
    dftRecursiveInorder(current->getRight());
}

void BinarySearchTree::dftRecursivePreorder(BSTNode *current) {
    
    if(current == NULL) return;
    cout << current << endl;
    dftRecursivePreorder(current->getLeft());
    dftRecursivePreorder(current->getRight());
}

void BinarySearchTree::dftRecursivePostorder(BSTNode *current) {
    
    if(current == NULL) return;
    dftRecursivePostorder(current->getLeft());
    dftRecursivePostorder(current->getRight());
    cout << current << endl;
}

void BinarySearchTree::bft() {
    
    BSTNode *node = _root;
    
    Queue* queue = new Queue();
    
    queue->enqueue(node);
    
    while (!queue->empty()) {
        
        cout << queue->dequeue() << endl;
        
        if (node->getLeft() != NULL) {
            
            queue->enqueue(node->getLeft());
            
        }
        
        if (node->getRight() != NULL) {
            
            queue->enqueue(node->getRight());
            
        }
    }
}
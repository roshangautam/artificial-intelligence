//
//  BinarySearchTree.cpp
//  BST
//
//  Created by Roshan Gautam on 5/31/16.
//  Copyright © 2016 Roshan Gautam. All rights reserved.
//

#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() {
    // Default constructor, set root to 0
    _root = NULL;
}

BinarySearchTree::BinarySearchTree(BSTNode *root) {
    // Constructor to create a tree with given node as the root
    _root = root;
}

BSTNode* BinarySearchTree::search(int value) {
    // Search for a value in this tree

    // Assume what we are looking for is in root node
    BSTNode *found = _root;
    
    // keep loooking until we dont find what we are looking for OR theres nothing left
    while(found != NULL && found->getValue() != value) {
        
        if(value < found->getValue()) {
            
            found = found->getLeft();
            
        } else {
            
            found = found->getRight();
        }
    }
    
    // return the findings
    return found;
}

BSTNode* BinarySearchTree::getRoot() {
    // return root of this tree
    return _root;
}

bool BinarySearchTree::insert(int value) {
    //Insert a given value to this tree

    //Create a new node 
    BSTNode* node = new BSTNode(value);

    // variable to help us iterate over the tree
    BSTNode* iterator = NULL;

    // temp variable to help us with insertion
    BSTNode* temp = NULL;
    
    // ABORT, Cant create node
    if(!node) return false;
    
    // Check if root is null
    if(_root == NULL)
        _root = node; // if root is null make the new node root of this tree
    else {
        // root is not null
        iterator = _root; // assign root to the iterator
        temp = _root; // assign root to the temp variable
        
        while(iterator) { // while there are nodes left in the tree
            temp = iterator; // save the current node to temp
            if(value < temp->getValue()) // if the value to be inserted is smaller than current nodes value go to the left subtree
                iterator = iterator->getLeft();
            else // if the value to be inserted is greater than current nodes value go to the right subtree
                iterator = iterator->getRight();
        }
        // We have reached the end of the correct side of the tree depending the new value
        if(value < temp->getValue())
            temp->setLeft(node); // if the value to be inserted is smaller than current nodes value , make the new node left pointer of current node
        else
            temp->setRight(node); // if the value to be inserted is greater than current nodes value , make the new node right pointer of current node
    }
    
    return true;
}
// Postorder traversal of the tree
void BinarySearchTree::dftIterativePostorder() {
    // Start from the root
    BSTNode* node = _root;

    // Create a new stack
    Stack* stack = new Stack();

    // Temp variable to track what node was visited recently
    BSTNode* lastVisitedNode = NULL;
    

    // while stack is not empty OR current node is not null
    while(!stack->empty() || node != NULL) {
        
        // if node is not null
        if(node != NULL) {
            
            // push it to the stack
            stack->push(node);
            
            // make the left pointer current node
            node = node->getLeft();
            
        } else { // if node is null
            
            // see whats on top
            BSTNode* peekNode = stack->peek();
            
            // if the top most nodes right pointer is not null and the right node is not the one we visted last
            if(peekNode->getRight() != NULL && lastVisitedNode != peekNode->getRight())
                
                // make the current node the right pointer of whats on top of the stack
                node = peekNode->getRight();
            
            else {
                
                // else print whats on top 
                cout << peekNode << endl;
                
                // pop and make it the last visited node
                lastVisitedNode = stack->pop();
            }
        }
    }
}

// Breadth First Traversal
void BinarySearchTree::bft() {
    // Start from the root
    BSTNode *node = _root;
    //Create a new queue
    Queue* queue = new Queue();
    // push the root the queue
    queue->enqueue(node);
    // while the queue is not empty
    while (!queue->empty()) {
        // dequeue and print the top node
        node = queue->dequeue();
        cout << node << endl;
        // Check for left
        if (node->getLeft() != NULL) queue->enqueue(node->getLeft()); // push the left node to the queue
        // Check for right
        if (node->getRight() != NULL) queue->enqueue(node->getRight()); // push the righ node to the queue
    }
}

// Extras

// Preorder traversal of the tree
void BinarySearchTree::dftIterativePreorder() {
    // Start from the root
    BSTNode* node = _root;

    // If root is null, list is empty
    if(node == NULL) return;
    
    // Create a new Stack
    Stack* stack = new Stack();
    
    // Push root to the stack
    stack->push(node);
    
    // While stack is not empty
    while(!stack->empty()) {

        // pop whats is top
        node = stack->pop();
        // print the freshly popped node first as this is preorder traversal
        cout << node << endl;
        // Check for right subtree
        if(node->getRight() != NULL) stack->push(node->getRight()); // push the right node to the stack            
        // check for left subtree
        if(node->getLeft() != NULL) stack->push(node->getLeft()); // push the left node to the stack
    }
}

// Inorder traversal of the tree, prints the values in ascending order
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


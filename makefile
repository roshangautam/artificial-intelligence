CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g $(shell root-config --cflags)
LDFLAGS=-g $(shell root-config --ldflags)
LDLIBS=$(shell root-config --libs)

SRCS=Main.cpp BinarySearchTree.cpp BSTNode.cpp Queue.cpp Stack.cpp UnorderedLinkedList.cpp ULLNode.cpp
OBJS=$(subst .cc,.o,$(SRCS))

all: BST

BST: $(OBJS)
	$(CXX) $(LDFLAGS) -o BST $(OBJS) $(LDLIBS) 

BST.o: main.cpp BinarySearchTree.h

BinarySearchTree.o: BinarySearchTree.cpp BSTNode.h
BSTNode.o: BSTNode.cpp Stack.h Queue.h
Stack.o: Stack.cpp UnorderedLinkedList.h
Queue.o: Queue.cpp UnorderedLinkedList.h
ULLNode.o: ULLNode.cpp BSTNode.h

clean:
	$(RM) $(OBJS)

dist-clean: clean
	$(RM) BST

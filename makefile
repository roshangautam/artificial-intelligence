CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g $(shell root-config --cflags)
LDFLAGS=-g $(shell root-config --ldflags)
LDLIBS=$(shell root-config --libs)

SRCS=Main.cpp AdjacencyMatrix.cpp Queue.cpp Stack.cpp UnorderedLinkedList.cpp ULLNode.cpp
OBJS=$(subst .cc,.o,$(SRCS))

all: main

main: $(OBJS)
	$(CXX) $(LDFLAGS) -o Graph $(OBJS) $(LDLIBS) 

main.o: main.cpp AdjacencyMatrix.h

AdjacencyMatrix.o: AdjacencyMatrix.cpp Stack.h Queue.h
Stack.o: Stack.cpp UnorderedLinkedList.h
Queue.o: Queue.cpp UnorderedLinkedList.h
ULLNode.o: ULLNode.cpp

clean:
	$(RM) $(OBJS)

dist-clean: clean
	$(RM) Graph

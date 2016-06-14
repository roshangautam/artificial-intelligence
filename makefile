CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g $(shell root-config --cflags)
LDFLAGS=-g $(shell root-config --ldflags)
LDLIBS=$(shell root-config --libs)

SRCS=Main.cpp Set.cpp Problem.cpp
OBJS=$(subst .cc,.o,$(SRCS))

all: main

main: $(OBJS)
	$(CXX) $(LDFLAGS) -o Problem $(OBJS) $(LDLIBS) 

main.o: main.cpp Problem.h

Problem.o: Problem.cpp Set.h Enums.h
Set.o: Set.cpp

clean:
	$(RM) $(OBJS)

dist-clean: clean
	$(RM) Problem

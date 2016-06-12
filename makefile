CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g $(shell root-config --cflags)
LDFLAGS=-g $(shell root-config --ldflags)
LDLIBS=$(shell root-config --libs)

SRCS=Main.cpp Set.cpp
OBJS=$(subst .cc,.o,$(SRCS))

all: main

main: $(OBJS)
	$(CXX) $(LDFLAGS) -o Set $(OBJS) $(LDLIBS) 

main.o: main.cpp Set.h

Set.o: Set.cpp

clean:
	$(RM) $(OBJS)

dist-clean: clean
	$(RM) Set

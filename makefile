CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g $(shell root-config --cflags)
LDFLAGS=-g $(shell root-config --ldflags)
LDLIBS=$(shell root-config --libs)

SRCS=Main.cpp
OBJS=$(subst .cc,.o,$(SRCS))

all: main

main: $(OBJS)
	$(CXX) $(LDFLAGS) -o Agent $(OBJS) $(LDLIBS) 

main.o: main.cpp


clean:
	$(RM) $(OBJS)

dist-clean: clean
	$(RM) Agent
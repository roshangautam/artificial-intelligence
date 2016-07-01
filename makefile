CC=gcc
CXX=g++
RM=rm -f
SRCS=Main.cpp WumpusEnvironment.cpp
OBJS=$(subst .cc,.o,$(SRCS))

all: WUMPUS

WUMPUS: $(OBJS)
	$(CXX) $(LDFLAGS) -o WUMPUS $(OBJS) $(LDLIBS) 

WUMPUS.o: main.cpp WumpusEnvironment.h

WumpusEnvironment.o: WumpusEnvironment.cpp

clean:
	$(RM) $(OBJS)

dist-clean: clean
	$(RM) WUMPUS

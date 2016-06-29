CC=gcc
CXX=g++
RM=rm -f
SRCS=Main.cpp
OBJS=$(subst .cc,.o,$(SRCS))

all: MINIMAX

MINIMAX: $(OBJS)
	$(CXX) $(LDFLAGS) -o MINIMAX $(OBJS) $(LDLIBS) 

MINIMAX.o: main.cpp

clean:
	$(RM) $(OBJS)

dist-clean: clean
	$(RM) MINIMAX

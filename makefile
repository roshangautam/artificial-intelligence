CC=gcc
CXX=g++
RM=rm -f

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
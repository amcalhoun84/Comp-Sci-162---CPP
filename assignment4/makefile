CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

PROGS := assignment4

all: $(PROGS)

assignment4: main.cpp fight.cpp fight.hpp characterType.cpp characterType.hpp goblin.hpp goblin.cpp barbarian.hpp barbarian.cpp reptilePeople.hpp reptilePeople.cpp blueMen.hpp blueMen.cpp theShadow.hpp theShadow.cpp frontEnd.hpp frontEnd.cpp stack.hpp stack.cpp queue.hpp queue.cpp node.hpp node.cpp
	g++ -g -Wall -pedantic-errors main.cpp fight.cpp fight.hpp characterType.cpp characterType.hpp goblin.hpp goblin.cpp barbarian.hpp barbarian.cpp reptilePeople.hpp reptilePeople.cpp blueMen.hpp blueMen.cpp theShadow.hpp theShadow.cpp frontEnd.hpp frontEnd.cpp stack.hpp stack.cpp queue.hpp queue.cpp node.hpp node.cpp -o assignment4
	
clean:
	rm -f $(PROGS) *.o*~ assignment4
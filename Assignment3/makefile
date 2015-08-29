CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

PROGS := assignment3

all: $(PROGS)

assignment3: main.cpp fight.cpp fight.hpp characterType.cpp characterType.hpp goblin.hpp goblin.cpp barbarian.hpp barbarian.cpp reptilePeople.hpp reptilePeople.cpp blueMen.hpp blueMen.cpp theShadow.hpp theShadow.cpp frontEnd.hpp frontEnd.cpp
	g++ -g -Wall -pedantic-errors main.cpp fight.cpp fight.hpp characterType.cpp characterType.hpp goblin.hpp goblin.cpp barbarian.hpp barbarian.cpp reptilePeople.hpp reptilePeople.cpp blueMen.hpp blueMen.cpp theShadow.hpp theShadow.cpp frontEnd.hpp frontEnd.cpp -o assignment3
	
clean:
	rm -f $(PROGS) *.o*~
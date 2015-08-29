CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

PROGS := libraryInventory

all: $(PROGS)

libraryInventory: item.cpp item.hpp audiobook.cpp audiobook.hpp book.cpp book.hpp video.cpp video.cpp library.cpp library.cpp main.cpp 
	g++ -g -Wall -pedantic-errors item.cpp audiobook.cpp book.cpp video.cpp library.cpp main.cpp -o libraryInventory
	
clean:
	rm -f $(PROGS) *.o*~
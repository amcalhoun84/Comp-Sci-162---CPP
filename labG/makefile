PROGS := labG

all: $(PROGS)

labG: main.cpp binarySearch.cpp bubbleSort.cpp targetSearch.cpp 
	g++ -g main.cpp targetSearch.cpp binarySearch.cpp bubbleSort.cpp -o labG
	
clean:
	rm -f $(PROGS) *.o*~
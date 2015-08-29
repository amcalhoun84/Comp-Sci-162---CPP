PROGS := labFa

all: $(PROGS)

labFa: main.cpp queue.hpp queue.cpp stack.hpp stack.cpp node.hpp node.cpp
	g++ main.cpp queue.hpp queue.cpp stack.hpp stack.cpp node.hpp node.cpp -o labFa

clean:
	rm -f $(PROGS) *.o*~
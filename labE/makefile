PROGS := labE

all: $(PROGS)

labE: fileFilter.cpp copy.cpp upper.cpp fileEncryption.cpp cipherFilter.cpp main.cpp 
	g++ -g fileFilter.cpp copy.cpp upper.cpp fileEncryption.cpp cipherFilter.cpp main.cpp -o labE
	
clean:
	rm -f $(PROGS) *.o*~
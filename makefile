all: submission

submission: LCS.o
	g++ -g LCS.o -o submission
	
LCS.o: LCS.cpp
	g++ -g -c LCS.cpp
	
clean:
	rm -f *.o submission

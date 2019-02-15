#program: assign6
#programmer: justin roesner z1858242

#compiler variables
CCFlags = -Wall -std=c++11

#rule to link object code to create executable file
assign6: assign6.o 
	g++ $(CCFLAGS) -o assign6 assign6.o 

#rules to compile source code files to object code
assign6.o: assign6.cpp Queue.h
	g++ $(CCFLAGS) -c assign6.cpp

#pseudo target to remove object code and executable files
clean:
	-rm *.o assign6

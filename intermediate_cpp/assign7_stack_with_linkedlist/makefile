#program:assign7
#programmer: justin roesner z1858242

#compiler variables
CCFlags = -Wall -std=c++11

#rule to link object code to create executable file
assign7: assign7.o 
		g++ $(CCFLAGS) -o assign7 assign7.o 

#rules to compile source code files to object code
assign7.o: assign7.cpp Stack.h
		g++ $(CCFLAGS) -c assign7.cpp

#pseudo target to remove object code and executable files
clean:
	-rm *.o assign7

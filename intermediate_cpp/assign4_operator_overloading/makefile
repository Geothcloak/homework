#program: assign3
#programmer: justin roesner z1858242

#compiler variables
CCFlags = -Wall -std=c++11

#rule to link object code to create executable file
assign4: assign4.o Complex.o
	g++ $(CCFLAGS) -o assign4 assign4.o Complex.o

#rules to compile source code files to object code
assign4.o: assign4.cpp Complex.h
	g++ $(CCFLAGS) -c assign4.cpp

Complex.o: Complex.cpp Complex.h
	g++ $(CCFLAGS) -c Complex.cpp

#pseudo target to remove object code and executable files
clean:
	-rm *.o assign4

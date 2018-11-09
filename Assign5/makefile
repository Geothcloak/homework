#program: assign5
#programmer: justin roesner z1858242

#compiler variables
CCFlags = -Wall -std=c++11

#rule to link object code to create executable file
assign5: assign5.o NIUString.o
	g++ $(CCFLAGS) -o assign5 assign5.o NIUString.o

#rules to compile source code files to object code
assign5.o: assign5.cpp NIUString.h
	g++ $(CCFLAGS) -c assign5.cpp

NIUString.o: NIUString.cpp NIUString.h
	g++ $(CCFLAGS) -c NIUString.cpp

#pseudo target to remove object code and executable files
clean:
	-rm *.o assign5

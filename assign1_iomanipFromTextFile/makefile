#
#PROGRAM: assign1
#PROGRAMMER: Justin Roesner
#LOGON ID: z1858242
#DATE DUE: 18-9-2018
#

#Compiler variables
CCFLAGS = -Wall -std=c++11

#Rule to link object code files to create executable file
assign1: assign1.o
	g++ $(CCFLAGS) -o assign1 assign1.o

#Rule to compile source code file to object code
assign1.o: assign1.cpp
	g++ $(CCFLAGS) -c assign1.cpp

#Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign1

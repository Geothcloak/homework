#program: assign8
#programmer: justin roesner z1858242

#compiler variables
CCFlags = -Wall -std=c++11

#rule to link object code to create executable file
assign8: assign8.o Maze.o
	g++ $(CCFLAGS) -o assign8 assign8.o Maze.o

#rules to compile source code files to object code
assign8.o: assign8.cpp Maze.h
	g++ $(CCFLAGS) -c assign8.cpp

Maze.o: Maze.cpp Maze.h
	g++ $(CCFLAGS) -c Maze.cpp

#pseudo target to remove object code and executable files
clean:
	-rm *.o assign8

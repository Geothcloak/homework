#program: assign3
#programmer: justin roesner z1858242

#compiler variables
CCFlags = -Wall -std=c++11

#rule to link object code to create executable file
assign3: assign3.o Maze.o
	g++ $(CCFLAGS) -o assign3 assign3.o Maze.o

#rules to compile source code files to object code
assign3.o: assign3.cpp Maze.h
	g++ $(CCFLAGS) -c assign3.cpp

Maze.o: Maze.cpp Maze.h
	g++ $(CCFLAGS) -c Maze.cpp

#pseudo target to remove object code and executable files
clean:
	-rm *.o assign3

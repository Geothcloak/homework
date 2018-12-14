#ifndef MAZE_H
#define MAZE_H

#include <string>
#include <stack>

using std::string;
using std::stack;

class Maze
{
	//enumerators
	enum SquareType
	{
		WALL = '#',
		SPACE = '.',
		START = 's',
		END = 'e'
	};

	enum PathType
	{
		NORTH = 'n',
		SOUTH = 's',
		EAST = 'e',
		WEST = 'w'
	};
	//structures
	struct MazePos
	{
		int xpos = 0;
		int ypos = 0;
	};

	struct MazeSquare
	{
		SquareType type;
		bool visited = false;
	};

	public:
	//variables
	MazeSquare mazeSquare[25][25];
	int width;
	int height;
	MazePos start;
	MazePos end;
	stack<char> path;

	//methods
	void readMaze(const string&);
	void printMaze() const;
	void clearPath();

	//new methods for assign8
	bool solveMaze();
	bool solveMaze(int, int);
	void printPath();

};
#endif


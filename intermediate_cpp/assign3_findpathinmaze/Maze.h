#ifndef MAZE_H
#define MAZE_H

#include <string>
using std::string;

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
		int xpos;
		int ypos;
	};

	struct MazeSquare
	{
		SquareType type;
		bool visited;
	};

	public:
	//variables
	MazeSquare mazeSquare[25][25];
	int width;
	int height;
	MazePos start;
	MazePos end;

	//methods
	void readMaze(const string&);
	void printMaze() const;
	void clearPath();
	bool readAndCheckPath(const string&);

};
#endif







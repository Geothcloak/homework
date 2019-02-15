/***************************************************************
PROGRAM:    CSCI 241 Assignment 8
PROGRAMMER: Justin Roesner
LOGON ID:   z1858242
DUE DATE:   11/28/18

FUNCTION:   Maze.cpp definition class.
 ***************************************************************/

#include "Maze.h"
#include <fstream>
#include <iostream>

using namespace std;

void Maze::readMaze(const string& fileName)
{
    //attempt to read file
    ifstream inFile(fileName);
    if (!inFile)
    {
        cout << "error unable to open file " << fileName << endl;
        exit(1);
    }

    //read height and width of the maze in as integers
    inFile >> height;
    inFile >> width;
    //temp variable to hold path before casting to squaretype
    char tempPath;
    for(int col = 0; col < height; col++)
    {
        for(int row = 0; row < width; row++)
        {
            //add the current space to the mazeSquare
            inFile >> tempPath; 
            mazeSquare[col][row].type = (SquareType)tempPath;
            //check if we are at the start
            if (mazeSquare[col][row].type == START)
            {
                start.xpos = row;
                start.ypos = col;
            }
            //check if we are at the end
            if (mazeSquare[col][row].type == END)
            {
                end.xpos = row;
                end.ypos = col;
            }
        }
    }
    inFile.close(); 
}

void Maze::printMaze() const
{
    //loop through one by one row printing the /characters
    for(int col = 0; col < height; col++)
    {
        for(int row = 0; row < width; row++)
        {
            cout << (char)mazeSquare[col][row].type;
            if (row == width -1)
            {
                cout << endl;
            }
        }
    }

}

//set all visted to false
void Maze::clearPath()
{
    for(int col = 0; col < height; col++)
    {
        for(int row = 0; row < width; row++)
        {
            mazeSquare[col][row].visited = false;
        }
    }
}

//returns true if solution for maze is found.
bool Maze::solveMaze()
{
    clearPath();
    return solveMaze(start.ypos, start.xpos);
}

//returns true if solution for maze is found.
bool Maze::solveMaze(int col, int row)
{

    if (row == end.xpos && col == end.ypos)
    {
        return true;
    }
    // If we hit a wall or we've already visited this square, this square is
    // not part of a valid path to the end of the maze.

    if (mazeSquare[col][row].visited == true || mazeSquare[col][row].type == WALL)
    {
        return false;
    }
    // Mark this square as visited
    mazeSquare[col][row].visited = true;

    // If we're not on the top edge of the maze, try to go north.
    if (row > 0)
    {
        if (solveMaze(col-1, row))
        {
            path.push('n');
            return true;
        }
    }

    // if we are not at the max height try south
    if (row < height)
    {
        if (solveMaze(col+1, row))
        {
            path.push('s');
            return true;
        }
    }

    // if not all the way west try west
    if (col > 0)
    {
        if (solveMaze(col, row-1))
        {
            path.push('w');
            return true;
        }
    }

    // if not all the way east try east
    if (col < width)
    {
        if (solveMaze(col, row+1))
        {
            path.push('e');
            return true;
        }
    }
    return false;
}

//prints a valid path through the maze
void Maze::printPath()
{
    while (!path.empty())
    {
        cout << path.top() << " ";
        path.pop();
    }
}


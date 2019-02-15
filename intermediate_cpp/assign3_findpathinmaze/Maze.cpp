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
    //loop through one by one row printing the characters
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
    for(int col = 0; col <= height; col++)
    {
        for(int row = 0; row <= width; row++)
        {
            mazeSquare[col][row].visited = false;
        }
    }
}

bool Maze::readAndCheckPath(const string& fileName)
{
    //attempt to read file
    ifstream inFile(fileName);
    if (!inFile)
    {
        cout << "error unable to open file " << fileName << endl;
        exit(1);
    }

    //clear visited paths
    clearPath();
    //set current location to starting position and set visted to true.
    int currentX = start.xpos;
    int currentY = start.ypos;
    mazeSquare[currentY][currentX].visited = true;

    char tempPathType;
    PathType currentPath;
    while (inFile >> tempPathType)
    {
        currentPath = (PathType)tempPathType;
        //move the current positions according to path
        if (currentPath == NORTH)
        {
            currentY--; 
        }
        if (currentPath == SOUTH)
        { 
            currentY++;
        }
        if (currentPath == EAST)
        {
            currentX++; 
        }
        if (currentPath == WEST)
        {
            currentX--; 
        }
        //check if we are out of bounds
        if (currentY > height||currentX > width||currentY<0||currentX<0)
        {
            return false;
        }

        // <= 0?
        //
        //check if we double backed
        if (mazeSquare[currentY][currentX].visited == true)
        {
            return false;
        }
        //check if we hit a wall
        if (mazeSquare[currentY][currentX].type == WALL)
        {
            return false;
        }
        //check if we are at the end
        if (currentY == end.ypos && currentX == end.xpos)
        {
            inFile.close();
            return true;
        }
        mazeSquare[currentY][currentX].visited = true;
    }

    inFile.close();
    return false;
}



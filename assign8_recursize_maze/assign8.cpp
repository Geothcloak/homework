/***************************************************************
PROGRAM:    CSCI 241 Assignment 8
PROGRAMMER: Justin Roesner
LOGON ID:   z1858242
DUE DATE:   11/28/18

FUNCTION:   This program tests the functionality of the
Maze class.
 ***************************************************************/

#include <iostream>
#include <string>
#include "Maze.h"

using std::cout;
using std::endl;
using std::to_string;
using std::flush;

int main()
{
    Maze m;

    for (int i = 1; i <= 3; ++i)
    {
        m.readMaze("maze" + to_string(i) + ".txt");

        m.printMaze();

        cout << endl;
        cout << " ";

        if (m.solveMaze())
        {
            cout << "Valid path: ";
            m.printPath();
            cout << endl;
        }
        else
        {
            cout << "There is no valid path through this maze.\n";
        }
    }

    return 0;
}

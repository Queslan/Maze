#include "MazeCreate.h"
#include <dataStruct.h>
#include <GLFW/glfw3.h>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <iostream>



MazeCreate::MazeCreate()
{
	makeSketch();
	conversion();
}


MazeCreate::~MazeCreate()
{
}

void MazeCreate::makeSketch()
{
	std::vector <int> row(n);
	for (int i = 0; i < n; i++)
	{
		switch (i)
		{
		case 0:row = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }; // 0
			   break;
		case 1:row = { 0,1,0,1,1,1,0,0,1,0,0,1,0,0,0,0 }; // 1
			   break;
		case 2:row = { 0,1,0,1,0,1,1,0,1,1,1,1,1,1,1,0 }; // 2
			   break;
		case 3:row = { 0,1,0,0,0,1,0,1,1,0,0,0,0,0,0,0 }; // 3
			   break;
		case 4:row = { 0,1,0,1,1,1,0,0,1,1,1,0,0,1,0,0 }; // 4
			   break;
		case 5:row = { 0,1,0,0,0,1,0,0,0,0,1,0,0,1,1,0 }; // 5
			   break;
		case 6:row = { 0,1,0,1,1,1,1,1,1,1,1,1,1,1,0,0 }; // 6
			   break;
		case 7:row = { 0,1,0,1,0,0,1,0,0,0,0,1,0,1,1,0 }; // 7
			   break;
		case 8:row = { 0,1,0,1,1,0,1,0,1,1,0,1,0,1,0,0 }; // 8
			   break;
		case 9:row = { 0,1,0,0,0,0,1,0,1,0,0,1,0,1,0,0 }; // 9
			   break;
		case 10:row = { 0,1,1,1,1,1,1,0,1,0,0,1,0,1,0,0 }; // 10
				break;
		case 11:row = { 0,1,0,0,0,0,0,0,1,1,1,1,0,1,0,0 }; // 11
				break;
		case 12:row = { 0,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0 }; // 12
				break;
		case 13:row = { 0,1,0,1,0,0,1,0,1,1,0,1,0,0,1,0 }; // 13
				break;
		case 14:row = { 0,1,0,1,1,1,1,1,1,0,1,1,2,1,1,0 }; // 14
				break;
		case 15:row = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }; // 15
				break;
		}
		sketch.push_back(row);
		row.clear();
	}
}

void MazeCreate::conversion()
{
	std::vector <dataStruct*> rowMaze(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			rowMaze[j] = new dataStruct();
			if (sketch[i][j] == 2)
			{
				rowMaze[j]->isFinish = true;
			}
			else if (sketch[i][j] == 0)
			{
				rowMaze[j]->isWall = true;
			}
		}
		maze.push_back(rowMaze);
	}
}
void MazeCreate::draw()
{
	std::time_t timer = std::time(NULL);
	m_bBlinkStep = false;
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j <16; j++)
		{
			glColor3f(0, 0, 0);
			if (maze[i][j]->isFinish)
				glColor3f(1, 0, 0);
			else
				if (maze[i][j]->Visited) 
				{
					glColor3f(1.0 , 1.0, 0);
				}
				else
					if (maze[i][j]->isWall)
						glColor3f(0, 0, 0);
					else

						if (!maze[i][j]->isFinish && !maze[i][j]->isWall)
							glColor3f(1.0, 1.0, 1.0);
						else
							if(maze[i][j]->isFinish)
								glColor3f(0.0, 1.0, 1.0);

			timer = std::time(NULL);
			glRectf(i, j, i + 1, j + 1);
		}
	}

}

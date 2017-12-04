#pragma once
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <GLFW\glfw3.h>
#include <dataStruct.h>
class MazeCreate
{
public:

		std::vector < std::vector <int> > sketch;
		std::vector < std::vector <dataStruct*>> maze;
		bool m_bBlinkStep;
		const int n = 16;
		MazeCreate();

		~MazeCreate();

		void makeSketch();

		/*void showSketch()
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					std::cout << sketch[i][j];
					glColor3f(1, 1, 1);
					glRectf(i, j, i + 1, j + 1);
				}
				std::cout << std::endl;
			}
		}*/
		void conversion();
		std::vector<std::vector <dataStruct*>> *returnMaze()
		{
			return &maze;
		}
		void draw();
};


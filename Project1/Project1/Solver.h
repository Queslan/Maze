#pragma once
#include "MazeCreate.h"
#include <dataStruct.h>
class Solver
{
public:
	int x, y;
	
	std::vector<std::vector <dataStruct*>> *maze;
	Solver(std::vector<std::vector <dataStruct*>> *Arg, int x, int y);
	~Solver();
	void mazeLoop();
	std::vector<std::pair<int, int>> notWall();
};


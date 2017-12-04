#include "Solver.h"
#include <thread>
#include <chrono>




Solver::Solver(std::vector<std::vector <dataStruct*>> *Arg, int x, int y) :maze(Arg), x(x), y(y)
{
	new std::thread(&Solver::mazeLoop, this);
}


Solver::~Solver()
{
	
}

std::vector<std::pair<int, int>> Solver::notWall()
{
	std::vector<std::pair<int, int>> check;
	if (!((*maze)[x - 1][y]->isWall))
	{
		check.push_back(std::pair<int, int>(x - 1, y));
	}
	if (!((*maze)[x + 1][y]->isWall))
	{
		check.push_back(std::pair<int, int>(x + 1, y));
	}
	if (!((*maze)[x][y - 1]->isWall))
	{
		check.push_back(std::pair<int, int>(x, y - 1));
	}
	if (!((*maze)[x][y + 1]->isWall))
	{
		check.push_back(std::pair<int, int>(x, y + 1));
	}
	return check;
}
void Solver::mazeLoop()
{
	
	while (true)
	{
		std::vector<std::pair<int, int>> check = notWall();
		if ((*maze)[x][y]->isFinish)
		{
			break;
		}
		if (check.size() == 0)
		{
			break;
		}
		else if (check.size() == 1)
		{
			if ((*maze)[x][y]->mutex.try_lock())
			{
				(*maze)[x][y]->Visited = true;
				x = check.at(0).first;
				y = check.at(0).second;
			}
			else
			{
				break;
			}

		}
		else if (check.size() == 2)
		{
			if ((*maze)[x][y]->mutex.try_lock())
			{
				(*maze)[x][y]->Visited = true;
				x = check.at(0).first;
				y = check.at(0).second;
			}
			else
			{
				break;
			}
			new Solver(maze, check.at(1).first, check.at(1).second);
		}
		else
		{
			if ((*maze)[x][y]->mutex.try_lock())
			{
				(*maze)[x][y]->Visited = true;
				x = check.at(0).first;
				y = check.at(0).second;

			}
			else
			{
				break;
			}
			new Solver(maze, check.at(1).first, check.at(1).second);
			new Solver(maze, check.at(2).first, check.at(2).second);
		}
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

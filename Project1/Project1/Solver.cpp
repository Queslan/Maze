#include "Solver.h"
#include <thread>
#include <chrono>




Solver::Solver(std::vector<std::vector <dataStruct*>> *Arg, int x, int y) :maze(Arg), x(x), y(y)
{
	srand(time(NULL));
	rand_number = number;
	number = (number + 123) % 999;
	
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	std::cout << rand_number << std::endl;
	new std::thread(&Solver::mazeLoop, this);
}


Solver::~Solver()
{
	
}

std::vector<std::pair<int, int>> Solver::notWall()
{
	std::vector<std::pair<int, int>> check;
	if (!((*maze)[x][y-1]->isWall) && !((*maze)[x][y - 1]->Visited))
	{
		check.push_back(std::pair<int, int>(x, y - 1));
	}
	if (!((*maze)[x][y+1]->isWall) && !((*maze)[x][y + 1]->Visited))
	{
		check.push_back(std::pair<int, int>(x, y + 1));
	}
	if (!((*maze)[x-1][y]->isWall) && ! ((*maze)[x-1][y]->Visited))
	{
		check.push_back(std::pair<int, int>(x - 1, y));
	}
	if (!((*maze)[x+1][y]->isWall) && !((*maze)[x+1][y]->Visited))
	{
		check.push_back(std::pair<int, int>(x + 1, y));
	}
	return check;
}
void Solver::mazeLoop()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(50));
	while (true)
	{
		std::vector<std::pair<int, int>> check = notWall();
		if ((*maze)[x][y]->isFinish)
		{
			break;
		}
		if (check.size() == 0)
		{
			(*maze)[x][y]->Visited = true;
			(*maze)[x][y]->VisitedBy = rand_number;
			break;
		}
		else if (check.size() == 1)
		{
			if ((*maze)[x][y]->mutex.try_lock())
			{
				(*maze)[x][y]->Visited = true;
				(*maze)[x][y]->VisitedBy = rand_number;
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
				(*maze)[x][y]->VisitedBy = rand_number;
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
				(*maze)[x][y]->VisitedBy = rand_number;
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
	std::this_thread::sleep_for(std::chrono::milliseconds(200));
}
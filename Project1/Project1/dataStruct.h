#pragma once
#include <mutex>

static int number = 123;
struct dataStruct
{
	bool isWall;
	bool isFinish;
	std::mutex mutex;
	bool Visited;
	int VisitedBy;
	dataStruct()
	{
		isWall = false;
		isFinish = false;
		Visited = false;
		VisitedBy = 999;
	}
};
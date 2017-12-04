#pragma once
#include <mutex>
struct dataStruct
{
	bool isWall;
	bool isFinish;
	std::mutex mutex;
	bool Visited;
	dataStruct()
	{
		isWall = false;
		isFinish = false;
		Visited = false;
	}
};
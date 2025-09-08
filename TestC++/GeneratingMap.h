#pragma once
#include "MapNode.h"
#include "Enums.h"
class GeneratingMap
{
private:
	TestCases selectedCase;
	unsigned int size;
	MapNode** _map;
	void FillMap();
public:
	MapNode endNode;
	MapNode startNode;
	GeneratingMap();
	GeneratingMap(TestCases desiredCase, int newSize);
	Node GetNode(int x,int y);
	bool CheckNode(int x, int y);
	void ResetVisitFlags();
};


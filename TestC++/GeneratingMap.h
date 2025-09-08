#pragma once
#include "MapNode.h"
#include "Enums.h"
class GeneratingMap
{
private:
	int selectedCase;
	unsigned int size;
	MapNode** map;
	void FillMap();
public:
	MapNode endNode;
	MapNode startNode;
	GeneratingMap();
	GeneratingMap(TestCases desiredCase, int newSize);
	Node GetNode(int x,int y);
	void ResetVisitFlags();
};


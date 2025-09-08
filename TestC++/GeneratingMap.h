#pragma once
#include "TestRunner.h"
#include "MapNode.h"
class GeneratingMap
{
private:
	TestCases selectedCase;
	unsigned int size;
	MapNode** map;
	void FillMap();
public:
	GeneratingMap();
	GeneratingMap(TestCases desiredCase, int newSize);
	Node GetNode(int x,int y);
	void ResetVisitFlags();
};


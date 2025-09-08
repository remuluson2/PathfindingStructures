#include "GeneratingMap.h"
#include <stdexcept>
GeneratingMap::GeneratingMap() 
{
	selectedCase = TestCases::BEST;
	size = 10;
	FillMap();
}

GeneratingMap::GeneratingMap(TestCases desiredCase, int newSize)
{
	selectedCase = desiredCase;
	size = newSize;
	FillMap();
}

void GeneratingMap::FillMap() {
	map = new MapNode * [size];
	for (int i = 0; i < size; i++)
	{
		map[i] = new MapNode[size];
		for (int j = 0; j < size; j++) {
			map[i][j] = MapNode(i,j);
		}
	}
	if (selectedCase == TestCases::WORST)
	{
		for (int i = 1; i < size - 1; i++)
		{
			map[i][98].isPassable = false;
		}
	}
}

void GeneratingMap::ResetVisitFlags() {
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			map[i][j].wasVisited = false;
}

Node GeneratingMap::GetNode(int x, int y)
{
	MapNode node = map[y][x];
	if (node.isPassable == false || node.wasVisited == true) {
		throw new std::out_of_range("Node is not a valid target");
	}
	return Node(node.x, node.y);
}
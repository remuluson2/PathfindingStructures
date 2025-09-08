#include "GeneratingMap.h"
#include <stdexcept>
GeneratingMap::GeneratingMap() 
{
}

GeneratingMap::GeneratingMap(TestCases desiredCase, int newSize)
{
	selectedCase = desiredCase;
	size = newSize;
	FillMap();
}

void GeneratingMap::FillMap() {
	_map = new MapNode * [size];
	for (int i = 0; i < size; i++)
	{
		_map[i] = new MapNode[size];
		for (int j = 0; j < size; j++) {
			_map[i][j] = MapNode(j,i);
		}
	}
	if (selectedCase == TestCases::WORST)
	{
		for (int i = 1; i < size - 1; i++)
		{
			_map[i][size - 2].isPassable = false;
		}
		startNode = _map[size - 3][size / 2];
		endNode = _map[size - 1][size / 2];
	}
	else {
		startNode = _map[0][size / 2];
		endNode = _map[size - 1][size / 2];
	}
}

void GeneratingMap::ResetVisitFlags() {
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			_map[i][j].wasVisited = false;
}

Node GeneratingMap::GetNode(int x, int y)
{
	MapNode node = _map[y][x];
	node.wasVisited = true;
	return Node(node.x, node.y);
}

bool GeneratingMap::CheckNode(int x, int y)
{
	if ((x < 0 || x > size - 1) || (y < 0 || y > size - 1)) {
		return false;
	}
	auto node = _map[y][x];
	return node.isPassable == true && node.wasVisited == false;
}

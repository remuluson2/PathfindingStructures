#include "GeneratingMap.h"
#include <stdexcept>
#include <iostream>
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
	for (int y = 0; y < size; y++)
	{
		_map[y] = new MapNode[size];
		for (int x = 0; x < size; x++) {
			_map[y][x] = MapNode(x,y);
		}
	}
	if (selectedCase == TestCases::WORST)
	{
		for (int y = 1; y < size - 1; y++)
		{
			_map[y][size - 2].isPassable = false;
		}
		startNode = _map[size / 2][size - 3];
		endNode = _map[size / 2][size - 1];
	}
	else {
		startNode = _map[size / 2][0];
		endNode = _map[size / 2][size - 1];
	}
}

void GeneratingMap::ResetVisitFlags() {
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			_map[i][j].wasVisited = false;
}

void GeneratingMap::PrintMap()
{
	for (int y = 0; y < size; y++) {
		for (int x = 0; x < size; x++)
		{
			if (CheckNode(x, y))
			{
				std::cout << "O";
			} else {
				std::cout << "X";
			}
		}
		std::cout << "\n";
	}
}

Node GeneratingMap::GetNode(int x, int y)
{
	MapNode node = _map[y][x];
	_map[y][x].wasVisited = true;
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

void GeneratingMap::VisitNode(int x, int y)
{
	_map[y][x].wasVisited = true;
}

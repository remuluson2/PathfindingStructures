#pragma once
#include "GeneratingMap.h"
#include "Node.h"
#include "HeapBase.h"
#include <memory>
class MapSolver
{
	std::unique_ptr<HeapBase> openNodesCollection;
	GeneratingMap map;
	void AddChildrenNodes(Node currentNode, Node EndNode);
	int GetTaxicabDistance(Node inputNode, Node endNode);
public:
	MapSolver(std::unique_ptr<HeapBase> heap, GeneratingMap map);
	bool FindPath();
	void Reset();
};


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
	void GetTaxicabDistanceToEndNode(Node inputNode);
public:
	MapSolver(std::unique_ptr<HeapBase> heap, GeneratingMap map);
	bool FindPath();
};


#include "MapSolver.h"

void MapSolver::AddChildrenNodes(Node currentNode, Node EndNode)
{
}

void MapSolver::GetTaxicabDistanceToEndNode(Node inputNode)
{
}

MapSolver::MapSolver(std::unique_ptr<HeapBase> heap, GeneratingMap newMap) {
	map = newMap;
	this->openNodesCollection = std::move(heap);
	openNodesCollection->AddNode(Node());
	auto check = openNodesCollection->IsNullOrEmpty();
	//Deallokacja wezlow znajdujacych sie na stosie
	openNodesCollection->Clear();
	//deallokacja stosu po wykonaniu wszystkich operacji
	openNodesCollection.reset();
}

bool MapSolver::FindPath() {
	Node startNode = map.startNode.toNode();
	Node endNode = map.endNode.toNode();
	openNodesCollection->AddNode(startNode);
	while (!openNodesCollection->IsNullOrEmpty())
	{

	}
	return false;
}
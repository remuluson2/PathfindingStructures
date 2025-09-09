#include "MapSolver.h"

enum Directions {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

void MapSolver::AddChildrenNodes(Node currentNode, Node endNode)
{
	for (int i = (int)Directions::UP; i <= (int)Directions::RIGHT; i++)
	{
		int newy = currentNode.y;
		int newx = currentNode.x;
		switch (i)
		{
		case (int)Directions::UP:
			newy -= 1;
			break;
		case (int)Directions::DOWN:
			newy += 1;
			break;
		case (int)Directions::LEFT:
			newx -= 1;
			break;
		case (int)Directions::RIGHT:
			newx += 1;
			break;
		}

		if (map.CheckNode(newx, newy)) {
			Node node = map.GetNode(newx, newy);
			node.cost = currentNode.cost + 1;
			node.priority = node.cost + GetTaxicabDistance(node, endNode);
			openNodesCollection->AddNode(node);
		}
	}
}

int MapSolver::GetTaxicabDistance(Node inputNode, Node endNode)
{
	int distance = 0;
	distance = abs(inputNode.x - endNode.x) + abs(inputNode.y - endNode.y);
	return distance;
}

MapSolver::MapSolver(std::unique_ptr<HeapBase> heap, GeneratingMap newMap) {
	map = newMap;
	this->openNodesCollection = std::move(heap);
}

bool MapSolver::FindPath() {
	Node startNode = map.startNode.toNode();
	Node endNode = map.endNode.toNode();
	startNode.priority = GetTaxicabDistance(startNode, endNode);
	map.VisitNode(startNode.x, startNode.y);
	Node currentNode;
	openNodesCollection->AddNode(startNode);
	while (!openNodesCollection->IsNullOrEmpty())
	{
		currentNode = openNodesCollection->GetBestNode();
		
		if (GetTaxicabDistance(currentNode, endNode) == 0)
		{
			openNodesCollection->Clear();
			return true;
		}
		AddChildrenNodes(currentNode, endNode);
	}
	return false;
}

void MapSolver::Reset()
{
	openNodesCollection->Clear();
	map.ResetVisitFlags();
}

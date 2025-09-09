#include "MapNode.h"
Node MapNode::toNode()
{
	return Node(this->x, this->y);
}
MapNode::MapNode() {
	x = 0;
	y = 0;
}
MapNode::MapNode(int x, int y) {
	this->x = x;
	this->y = y;
}
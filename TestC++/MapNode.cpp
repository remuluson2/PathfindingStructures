#include "MapNode.h"
Node MapNode::toNode()
{
	return Node(this->x, this->y);
}
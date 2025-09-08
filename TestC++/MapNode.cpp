#include "MapNode.h"
Node MapNode::toNode()
{
	return Node(this->y, this->x);
}
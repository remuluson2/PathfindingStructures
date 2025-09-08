#pragma once
#include "Node.h"
class MapNode
{
public:
    int x, y;
    bool wasVisited = false;
    bool isPassable = true;
    Node toNode();
};


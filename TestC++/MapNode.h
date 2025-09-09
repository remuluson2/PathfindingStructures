#pragma once
#include "Node.h"
class MapNode
{
public:
    int x, y;
    bool wasVisited = false;
    bool isPassable = true;
    MapNode();
    MapNode(int x, int y);
    Node toNode();
};


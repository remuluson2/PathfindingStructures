#pragma once
#include "Node.h"
class HeapBase
{
public:
	virtual void ListHeap() = 0;
	virtual void Clear() = 0;
	virtual void AddNode(Node node) = 0;
	virtual Node GetBestNode() = 0;
	virtual bool IsNullOrEmpty() = 0;
};


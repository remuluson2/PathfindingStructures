#pragma once
#include "Node.h"
namespace PathfindingTester {
	class HeapBase
	{
	public:
		virtual void ListHeap() = 0;
		virtual void Clear() = 0;
		virtual void AddNode(Node node) = 0;
		virtual Node GetBestNode() = 0;
	};
}


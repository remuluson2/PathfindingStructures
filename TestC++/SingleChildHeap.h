#pragma once
#include "Node.h"
#include <vector>
namespace PathfindingTester {
    class SingleChildHeap
    {
    private:
        Node *_heap;
        int _size;
        void Swap(int firstIndex, int secondIndex);
        void Grow();
        void SortUp();
        void Shrink();
    public:
        void ListHeap();
        void Clear();
        void AddNode(Node node);
        Node GetBestNode();
    };
};
#pragma once
#include "Node.h"
#include "HeapBase.h"
#include <memory>
#include "ResultSaver.h"
namespace PathfindingTester {
    class SingleChildHeap : public HeapBase
    {
    private:
        std::unique_ptr<Node[]> _heap;
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
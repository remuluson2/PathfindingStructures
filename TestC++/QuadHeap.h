#pragma once
#pragma once
#include "Node.h"
#include "HeapBase.h"
#include "ResultSaver.h"
#include <memory>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <iostream>
namespace PathfindingTester {

    class QuadHeap : public HeapBase
    {
    private:
        std::unique_ptr<Node[]> _heap;
        int _size;
        void Swap(int firstIndex, int secondIndex);
        void Grow();
        void SortUp();
        void SortDown();
        void Shrink();
        //REDOINDEXES
        int parent(int i)
        {
            return (i - 1) / 2;
        }

        int leftChildIndex(int i)
        {
            return (2 * i + 1);
        }

        Node leftChild(int i)
        {
            return _heap[leftChildIndex(i)];
        }

        int rightChildIndex(int i)
        {
            return (2 * i + 2);
        }

        Node rightChild(int i)
        {
            return _heap[rightChildIndex(i)];
        }
    public:
        QuadHeap();
        void ListHeap();
        void Clear();
        void AddNode(Node node);
        Node GetBestNode();
    };
}
class QuadHeap
{
};


#pragma once
#include "Node.h"
#include <vector>
namespace PathfindingTester {
    class BinaryHeap
    {
    private:
        Node* _heap;
        int _size;
        void Swap(int firstIndex, int secondIndex);
        void Grow();
        void SortUp();
        void Shrink();
        int parent(int i) 
        { 
            return (i - 1) / 2; 
        }

        int leftChild(int i) 
        { 
            return (2 * i + 1); 
        }

        int rightChild(int i) 
        { 
            return (2 * i + 2); 
        }
    public:
        void ListHeap();
        void Clear();
        void AddNode(Node node);
        Node GetBestNode();
    };
}

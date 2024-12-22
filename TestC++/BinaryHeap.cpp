#include "BinaryHeap.h"
#include <algorithm>
#include <iterator>
#include <iostream>
using namespace PathfindingTester;

PathfindingTester::BinaryHeap::BinaryHeap()
{
    _size = 0;
    _heap = std::make_unique<Node[]>(0);
}

void PathfindingTester::BinaryHeap::Swap(int firstIndex, int secondIndex)
{
    Node temp = _heap[firstIndex];
    _heap[firstIndex] = _heap[secondIndex];
    _heap[secondIndex] = temp;
}

void PathfindingTester::BinaryHeap::Grow()
{
    _size++;
    auto newArray = std::make_unique<Node[]>(_size);

    for (int i = 0; i < _size - 1; i++) {
        newArray[i + 1] = _heap[i];
    }
    _heap = std::move(newArray);
}

void PathfindingTester::BinaryHeap::SortUp()
{
    int index = _size - 1;
    Node x = _heap[parent(index)];
    while (index != 0 && (_heap[index].cost < _heap[parent(index)].cost))
    {
        int parentIndex = parent(index);
        Swap(parentIndex, index);
        index = parentIndex;
    }
}

void PathfindingTester::BinaryHeap::SortDown()
{
    int index = 0;
    while (leftChildIndex(index) < _size)
    {
        int smallerIndex = leftChildIndex(index);
        if (rightChildIndex(index) < _size && rightChildIndex(index) < leftChildIndex(index))
        {
            smallerIndex = rightChildIndex(index);
        }

        if (_heap[smallerIndex].cost >= _heap[index].cost)
        {
            break;
        }

        Swap(smallerIndex, index);
        index = smallerIndex;
    }
}

void PathfindingTester::BinaryHeap::Shrink()
{
    _size--;
    auto newArray = std::make_unique<Node[]>(_size);
    if (_size > 0)
    {
        for (int i = 0; i < _size; i++) {
            newArray[i] = _heap[i + 1];
        }
    }
    _heap = std::move(newArray);
}

void PathfindingTester::BinaryHeap::Clear()
{
    std::cout << "\nClearing Array";
    /*for (int i = _size - 1; i > 0; i++)
    {
        std::cout << "\nDeleting element " + i;
        delete &_heap[i];
    }
    */
    _heap.reset();
    _size = 0;
}

void PathfindingTester::BinaryHeap::AddNode(Node node)
{
    Node newNode = Node();
    newNode.x = node.x;
    newNode.y = node.y;
    newNode.cost = node.cost;

    Grow();
    _heap[0] = newNode;
    SortDown();
}

Node PathfindingTester::BinaryHeap::GetBestNode()
{

    Node result = _heap[0];
    Shrink();

    return result;
}

void PathfindingTester::BinaryHeap::ListHeap() {
    for (int i = 0; i < _size; i++) {
        Node node = _heap[i];
        std::cout << "Node " << i << ": " << node.cost << " Parent: " << parent(i) << "\n";
    }
    if (_size == 0) std::cout << "Heap is empty.";
    std::cout << "\n";
}
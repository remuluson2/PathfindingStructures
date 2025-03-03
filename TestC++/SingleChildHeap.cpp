#include "SingleChildHeap.h"
#include <algorithm>
#include <iostream>
using namespace PathfindingTester;

void SingleChildHeap::Swap(int firstIndex, int secondIndex)
{
    Node temp = _heap[firstIndex];
    _heap[firstIndex] = _heap[secondIndex];
    _heap[secondIndex] = temp;
    ResultSaver::GetInstance()->numberOfSwaps++;
}

void PathfindingTester::SingleChildHeap::Grow()
{
    _size++;
    std::unique_ptr<Node[]> newArray(new Node[_size]);
    for (int i = 0; i < _size - 1; i++) {
        newArray[i + 1] = _heap[i];
    }
    _heap = std::move(newArray);
}

void PathfindingTester::SingleChildHeap::SortUp()
{
    unsigned int operationNum = 0;
    for (int index = 1; index < _size; index++)
    {
        operationNum++;
        if (_heap[index - 1].cost < _heap[index].cost)
        {
            break;
        }
        if (_heap[index - 1].cost != _heap[index].cost)
            Swap(index - 1, index);
    }
    ResultSaver::GetInstance()->numOfOperations += operationNum;
}

void PathfindingTester::SingleChildHeap::Shrink()
{
    _size--;
    std::unique_ptr<Node[]> newArray(new Node[_size]);
    if (_size > 0)
    {
        for (int i = 0; i < _size; i++) {
            newArray[i] = _heap[i + 1];
        }
    }
    _heap = std::move(newArray);
}

void PathfindingTester::SingleChildHeap::Clear()
{
    _heap.reset();
    _size = 0;
}

void PathfindingTester::SingleChildHeap::AddNode(Node node)
{
    Node newNode = Node();
    newNode.x = node.x;
    newNode.y = node.y;
    newNode.cost = node.cost;

    Grow();
    _heap[0] = newNode;
    SortUp();
}

Node PathfindingTester::SingleChildHeap::GetBestNode()
{

    Node result = _heap[0];
    Shrink();

    return result;
}

void PathfindingTester::SingleChildHeap::ListHeap() {
    for (int i = 0; i < _size; i++) {
        std::cout << "Node " << i << ": " << _heap[i].cost << "\n";
    }
    if (_size == 0) std::cout << "Heap is empty.";
    std::cout << "\n";
}
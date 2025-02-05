#include "QuadHeap.h"
using namespace PathfindingTester;

PathfindingTester::QuadHeap::QuadHeap()
{
    _size = 0;
    _heap = std::unique_ptr<Node[]>(0);
}

void PathfindingTester::QuadHeap::Swap(int firstIndex, int secondIndex)
{
    Node temp = _heap[firstIndex];
    _heap[firstIndex] = _heap[secondIndex];
    _heap[secondIndex] = temp;
    ResultSaver::GetInstance()->numberOfSwaps++;
}

void PathfindingTester::QuadHeap::Grow()
{
    _size++;
    std::unique_ptr<Node[]> newArray(new Node[_size]);
    for (int i = 0; i < _size - 1; i++) {
        newArray[i + 1] = _heap[i];
    }
    //std::cout << "freeing" << _size * sizeof(Node) << "bytes\n";
    _heap = std::move(newArray);
}

void PathfindingTester::QuadHeap::SortUp()
{
    unsigned int operationNum = 0;
    int index = _size - 1;
    Node x = _heap[parent(index)];
    while (index != 0 && (_heap[index].cost < _heap[parent(index)].cost))
    {
        operationNum++;
        int parentIndex = parent(index);
        Swap(parentIndex, index);
        index = parentIndex;
    }
    ResultSaver::GetInstance()->numOfOperations += operationNum;
}

void PathfindingTester::QuadHeap::SortDown()
{
    unsigned int operationNum = 0;
    int index = 0;
    while (leftChildIndex(index) < _size)
    {
        //TODO
    }
    ResultSaver::GetInstance()->numOfOperations += operationNum;
}

void PathfindingTester::QuadHeap::Shrink()
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

void PathfindingTester::QuadHeap::Clear()
{
    std::cout << "\nClearing Array";
    /*for (int i = _size - 1; i > 0; i++)
    {
        std::cout << "\nDeleting element " + i;
        delete &_heap[i];
    }*/
    //delete[] &_heap;

    _heap.reset();
    _size = 0;
}

void PathfindingTester::QuadHeap::AddNode(Node node)
{
    Node newNode = Node();
    newNode.x = node.x;
    newNode.y = node.y;
    newNode.cost = node.cost;

    Grow();
    _heap[0] = newNode;
    SortDown();
}

Node PathfindingTester::QuadHeap::GetBestNode()
{

    Node result = _heap[0];
    Shrink();

    return result;
}

void PathfindingTester::QuadHeap::ListHeap() {
    for (int i = 0; i < _size; i++) {
        Node node = _heap[i];
        std::cout << "Node " << i << ": " << node.cost << " Parent: " << parent(i) << "\n";
    }
    if (_size == 0) std::cout << "Heap is empty.";
    std::cout << "\n";
}
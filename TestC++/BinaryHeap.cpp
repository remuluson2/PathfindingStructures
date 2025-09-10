#include "BinaryHeap.h"
BinaryHeap::BinaryHeap()
{
    _size = 0;
    _heap = std::unique_ptr<Node[]>(0);
}

void BinaryHeap::Swap(int firstIndex, int secondIndex)
{
    Node temp = _heap[firstIndex];
    _heap[firstIndex] = _heap[secondIndex];
    _heap[secondIndex] = temp;
    ResultSaver::GetInstance()->numberOfSwaps++;
}

void BinaryHeap::Grow()
{
    _size++;
    std::unique_ptr<Node[]> newArray(new Node[_size]);
    for (int i = 0; i < _size - 1; i++) {
        newArray[i] = _heap[i];
    }
    _heap = std::move(newArray);
}

void BinaryHeap::SortUp()
{
    unsigned int operationNum = 0;
    int index = _size - 1;
    operationNum++;
    while (index != 0 && (_heap[index].priority < _heap[parent(index)].priority))
    {
        operationNum++;
        int parentIndex = parent(index);
        Swap(parentIndex, index);
        index = parentIndex;
    }
    ResultSaver::GetInstance()->numOfOperations += operationNum;
}

void BinaryHeap::SortDown()
{
    unsigned int operationNum = 0;
    int index = 0;
    while (leftChildIndex(index) < _size)
    {
        int smallerIndex = leftChildIndex(index);
        if (rightChildIndex(index) < _size && rightChildIndex(index) < leftChildIndex(index))
        {
            smallerIndex = rightChildIndex(index);
        }

        operationNum++;
        if (_heap[smallerIndex].priority >= _heap[index].priority)
        {
            break;
        }
        Swap(smallerIndex, index);
        index = smallerIndex;
    }
    ResultSaver::GetInstance()->numOfOperations += operationNum;
}

void BinaryHeap::Shrink()
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

void BinaryHeap::Clear()
{
    _heap.reset();
    _size = 0;
}

void BinaryHeap::AddNode(Node node)
{
    Node newNode = Node();
    newNode.x = node.x;
    newNode.y = node.y;
    newNode.cost = node.cost;
    newNode.priority = node.priority;

    Grow();
    _heap[_size - 1] = newNode;
    SortUp();
}

Node BinaryHeap::GetBestNode()
{
    Node result = _heap[0];
    Shrink();
    SortDown();

    return result;
}

void BinaryHeap::ListHeap() {
    for (int i = 0; i < _size; i++) {
        Node node = _heap[i];
        std::cout << "Node " << i << ": " << node.cost << " : " << node.priority << " cords:(" << node.x << ";" << node.y << ") Parent: " << parent(i) << "\n";
    }
    if (_size == 0) std::cout << "Heap is empty.";
    std::cout << "\n";
}

bool BinaryHeap::IsNullOrEmpty() {
    return _heap == NULL || _size < 1;
}
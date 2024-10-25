#include <iostream>
#include "SingleChildHeap.h"
using namespace std;
namespace pft = PathfindingTester;
int main()
{
    int i;
    float f;
    double d;
    Node node;

    Node* nodeptr = &node;

    int intlist[5];
    float floatlist[5];
    double doublelist[5];
    Node listNode[5];

    pft::SingleChildHeap nodeHeap = pft::SingleChildHeap();
    nodeHeap.AddNode(Node(1,1,10));
    nodeHeap.AddNode(Node(1, 2, 4));
    nodeHeap.AddNode(Node(1, 3, 8));
    nodeHeap.AddNode(Node(2, 3, 3));
    nodeHeap.ListHeap();
    Node bestNode = nodeHeap.GetBestNode();
    nodeHeap.ListHeap();
    bestNode = nodeHeap.GetBestNode();
    nodeHeap.ListHeap();
    bestNode = nodeHeap.GetBestNode();
    bestNode = nodeHeap.GetBestNode();

    nodeHeap.Clear();

    nodeHeap.ListHeap();
}
#include <iostream>
#include "SingleChildHeap.h"
#include "BinaryHeap.h"
#include "TestRunner.h"
#include "MemoryReader.h"
using namespace std;
using namespace PathfindingTester;
void* operator new(size_t size) {
    std::cout << "Allocating " << size << " bytes\n";

    return malloc(size);
}
void operator delete(void* memory, size_t size) {
    std::cout << "Freeing " << size << " bytes\n";

    free(memory);
}
void operator delete[](void* memory, size_t size) {
    std::cout << "Freeing " << size << " bytes\n";

    free(memory);
}
int main()
{
    TestRunner::RunTest();
}
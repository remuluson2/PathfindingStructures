#include "TestRunner.h"
#include <Psapi.h>
using namespace std;
using namespace PathfindingTester;
int main()
{
    HANDLE processHandle = GetCurrentProcess();
    SetPriorityClass(processHandle, 0x00000080);
    TestRunner::RunTest();
}
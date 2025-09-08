#pragma once
#include <windows.h>
#include "TestRunner.h"
using namespace std;
int main()
{

    HANDLE processHandle = GetCurrentProcess();
    SetPriorityClass(processHandle, 0x00000080);
    TestRunner::RunTest();
}
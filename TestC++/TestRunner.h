#pragma once
#include "SingleChildHeap.h"
#include "BinaryHeap.h"
#include "HeapBase.h"
#include "MemoryReader.h"
#include <iostream>
#include <cstdlib>
#include <memory>
#include <string>
#include <fstream>
#include <iostream>
namespace PathfindingTester {
	class TestRunner
	{
	public:
		static void RunTest();
		static Node GeneratePoint(int index);
		static void RunCase(int caseIndex, int structureIndex, int nodeNumber);
		static void SaveResult(std::string text);
	};
}


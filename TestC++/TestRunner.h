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
#include <chrono>
#include <cstdio>
namespace PathfindingTester {
	class TestRunner
	{
	public:
		static void RunTest();
		static Node GeneratePoint(int index);
		static void SimulateOperation(int caseIndex, int structureIndex, int nodeNumber);
		static void RunCase(int caseIndex, int structureIndex, int nodeNumber, int index);
		static void RunCases(int caseIndex, int structureIndex, int nodeNumber, int timesToRun);
		static void SaveResult(std::string text);
		static std::string CaseIndexToName(int caseIndex);
		static std::string StructureIndexToName(int structureIndex);
	};
}


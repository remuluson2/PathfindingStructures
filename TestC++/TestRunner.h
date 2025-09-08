#pragma once
#include "SingleChildHeap.h"
#include "MemoryReader.h"
#include "BinaryHeap.h"
#include "HeapBase.h"
#include "GeneratingMap.h"
#include <memory>
#include <string>
#include <chrono>
#include <iostream>
#include <filesystem>
enum TestCases {
	RANDOM = 0,
	WORST = 1,
	BEST = 2
};
enum MemoryStructures {
	SINGLECHILDHEAP = 1,
	BINARYHEAP = 2
};
class TestRunner
{
public:
	static void RunTest();
	static Node GeneratePoint(int index);
	static void SimulateOperation(TestCases caseIndex, int structureIndex, GeneratingMap* map);
	static void RunCase(TestCases caseIndex, int structureIndex, int nodeNumber, int index);
	static void RunCases(TestCases caseIndex, int structureIndex, int nodeNumber, int timesToRun);
	static void SaveResult(std::string text);
	static std::string CaseIndexToName(int caseIndex);
	static std::string StructureIndexToName(int structureIndex);
	static bool CheckIfTestCaseFilesArePresent(std::string fileName);
};


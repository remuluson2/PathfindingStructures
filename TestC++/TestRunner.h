#pragma once
#include "SingleChildHeap.h"
#include "Enums.h"
#include "MemoryReader.h"
#include "BinaryHeap.h"
#include "HeapBase.h"
#include "GeneratingMap.h"
#include "MapSolver.h"
#include <memory>
#include <string>
#include <chrono>
#include <iostream>
#include <filesystem>
class TestRunner
{
public:
	static void RunTest();
	static Node GeneratePoint(int index);
	static void RunCase(TestCases caseIndex, int structureIndex, int nodeNumber, int timestoRun);
	static void RunCases(TestCases caseIndex, int structureIndex, int nodeNumber, int timesToRun);
	static std::string CaseIndexToName(int caseIndex);
	static std::string StructureIndexToName(int structureIndex);
	static bool CheckIfTestCaseFilesArePresent(std::string fileName);
};


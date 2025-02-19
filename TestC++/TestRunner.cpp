#pragma once
#include "TestRunner.h"
enum TestCases {
	RANDOM = 0,
	WORST = 1,
	BEST = 2
};
enum MemoryStructures {
	SINGLECHILDHEAP = 1,
	BINARYHEAP = 2
};
void PathfindingTester::TestRunner::RunTest()
{
	std::cout << "\n\nStarting test!\n";
	std:srand(std::time(NULL));
	int const iterations = 10;
	int const multiplayer = 1000;
	int const targetDatapointNum = 100;
	for (int i = 1; i <= iterations; i++) {
		RunCases(BEST, SINGLECHILDHEAP, i * multiplayer, targetDatapointNum);
	}
	for (int i = 1; i <= iterations; i++) {
		RunCases(BEST, BINARYHEAP, i * multiplayer, targetDatapointNum);
	}
	for (int i = 1; i <= iterations; i++) {
		RunCases(WORST, BINARYHEAP, i * multiplayer, targetDatapointNum);
	}
	for (int i = 1; i <= iterations; i++) {
		RunCases(WORST, SINGLECHILDHEAP, i * multiplayer, targetDatapointNum);
	}

	RunCase(RANDOM, BINARYHEAP, 10000, 1);
	RunCase(RANDOM, SINGLECHILDHEAP, 10000, 1);
}

void PathfindingTester::TestRunner::RunCases(int caseIndex, int structureIndex, int nodeNumber, int timesToRun) {
	std::string resultfilename = "results/result" + StructureIndexToName(structureIndex) + CaseIndexToName(caseIndex) + std::to_string(nodeNumber) + ".csv";
	std::remove(resultfilename.c_str());
	for (int i = 1; i <= timesToRun; i++) {
		RunCase(caseIndex, structureIndex, nodeNumber, i);
	}
}

void PathfindingTester::TestRunner::RunCase(int caseIndex, int structureIndex, int nodeNumber, int index) {
	std::cout << "\n\nRunning Case!";
	std::cout << "\nCase " << caseIndex << " : nodeNum " << nodeNumber << "\n";
	auto start = std::chrono::high_resolution_clock::now();
	SimulateOperation(caseIndex, structureIndex, nodeNumber);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "Case took " << duration.count() << "ns to run.";
	ResultSaver::GetInstance()->executionTime = duration.count();
	ResultSaver::GetInstance()->SaveResultToFile(structureIndex, caseIndex, nodeNumber, index, nodeNumber);
}

void PathfindingTester::TestRunner::SimulateOperation(int caseIndex, int structureIndex, int nodeNumber)
{
	std::unique_ptr<HeapBase> nodeHeap;
	switch(structureIndex) {
	case 1:
		std::cout << "\nSetting SingleChildHeap\n";
		nodeHeap = std::make_unique<SingleChildHeap>();
		break;
	case 2:
		std::cout << "\nSetting BinaryHeap\n";
		nodeHeap = std::make_unique<BinaryHeap>();
		break;
	}
	switch (caseIndex) {
	case RANDOM:
		std::cout << "\nTesting RANDOM case\n";
		for (int i = 0; i < nodeNumber; i++) {
			nodeHeap->AddNode(TestRunner::GeneratePoint(i));
		}
		nodeHeap->Clear();
		break;
	case WORST:
		std::cout << "\nTesting WORST case\n";
		for (int i = 0; i < nodeNumber; i++) {
			nodeHeap->AddNode(Node(0, 0, i));
		}
		nodeHeap->Clear();
		break;
	case BEST:
		std::cout << "\nTesting BEST case\n";
		for (int i = 0; i < nodeNumber; i++) {
			nodeHeap->AddNode(Node(0, 0, nodeNumber - i));
		}
		nodeHeap->Clear();
		break;
	}
	std::cout << "\nReseting the heap holder!\n";
	nodeHeap.reset();
	std::cout << "\nCase done!\n";
}

void PathfindingTester::TestRunner::SaveResult(std::string text)
{
	std::ofstream MyFile("result.txt", std::ios_base::app);

	// Write to the file
	MyFile << text << "\n";

	// Close the file
	MyFile.close();
}

std::string PathfindingTester::TestRunner::CaseIndexToName(int caseIndex)
{
	std::string caseName;
	switch (caseIndex) {
	case 0:
		caseName = "RANDOM";
		break;
	case 1:
		caseName = "WORST";
		break;
	case 2:
		caseName = "BEST";
		break;
	}
	return caseName;
}

std::string PathfindingTester::TestRunner::StructureIndexToName(int structureIndex)
{
	std::string structName;
	switch (structureIndex) {
	case 1:
		structName = "SINGLEHEAP";
		break;
	case 2:
		structName = "BINARYHEAP";
		break;
	}
	return structName;
}

Node PathfindingTester::TestRunner::GeneratePoint(int index)
{
	Node result;
	result.cost = rand() % 1000;
	result.x = 0;
	result.y = 0;
	return result;
}

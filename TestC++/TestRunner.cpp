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
	std:srand(std::time(NULL));
	int const startvalue = 0;
	int const iterations = 10;
	int const multiplayer = 1000;
	int const targetDatapointNum = 100;
	//Test
	for (int i = 1; i <= iterations; i++) {
		RunCases(BEST, SINGLECHILDHEAP, i * multiplayer + startvalue, targetDatapointNum);
	}
	for (int i = 1; i <= iterations; i++) {
		RunCases(WORST, SINGLECHILDHEAP, i * multiplayer + startvalue, targetDatapointNum);
	}
	for (int i = 1; i <= iterations; i++) {
		RunCases(BEST, BINARYHEAP, i * multiplayer + startvalue, targetDatapointNum);
	}

	for (int i = 1; i <= iterations; i++) {
		RunCases(WORST, BINARYHEAP, i * multiplayer + startvalue, targetDatapointNum);
	}

	for (int i = 1; i <= iterations; i++) {
		RunCases(RANDOM, BINARYHEAP, i * multiplayer + startvalue, targetDatapointNum);
	}
	for (int i = 1; i <= iterations; i++) {
		RunCases(RANDOM, SINGLECHILDHEAP, i * multiplayer + startvalue, targetDatapointNum);
	}
}

void PathfindingTester::TestRunner::RunCases(int caseIndex, int structureIndex, int numberOfInsertedNodes, int timesToRun) {
	//Wynik z poprzedniego uruchomienia jest usuwany je�eli istnieje.
	std::string resultfilename = "results/result" + StructureIndexToName(structureIndex) + CaseIndexToName(caseIndex) + std::to_string(numberOfInsertedNodes) + ".csv";
	std::remove(resultfilename.c_str());
	for (int i = 1; i <= timesToRun; i++) {
		RunCase(caseIndex, structureIndex, numberOfInsertedNodes, i);
	}
}

void PathfindingTester::TestRunner::RunCase(int caseIndex, int structureIndex, int numberOfInsertedNodes, int index) {
	auto start = std::chrono::high_resolution_clock::now();
	SimulateOperation(caseIndex, structureIndex, numberOfInsertedNodes);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	ResultSaver::GetInstance()->executionTime = duration.count();
	ResultSaver::GetInstance()->SaveResultToFile(structureIndex, caseIndex, numberOfInsertedNodes, index, numberOfInsertedNodes);
}

void PathfindingTester::TestRunner::SimulateOperation(int caseIndex, int structureIndex, int numberOfInsertedNodes)
{
	std::unique_ptr<HeapBase> nodeHeap;
	//W zale�nosci od parametrow, zostaje utworzona odpowiednia struktura we wskazniku nodeHeap.
	switch(structureIndex) {
	case 1:
		nodeHeap = std::make_unique<SingleChildHeap>();
		break;
	case 2:
		nodeHeap = std::make_unique<BinaryHeap>();
		break;
	}
	//Obsluga przypadkow testowych
	switch (caseIndex) {
	case RANDOM:
		for (int i = 0; i < numberOfInsertedNodes; i++) {
			nodeHeap->AddNode(TestRunner::GeneratePoint(i));
		}
		break;
	case WORST:
		for (int i = 0; i < numberOfInsertedNodes; i++) {
			nodeHeap->AddNode(Node(0, 0, i));
		}
		break;
	case BEST:
		for (int i = 0; i < numberOfInsertedNodes; i++) {
			nodeHeap->AddNode(Node(0, 0, numberOfInsertedNodes - i));
		}
		break;
	}
	nodeHeap->ListHeap();
	//Deallokacja wezlow znajdujacych sie na stosie
	nodeHeap->Clear();
	//deallokacja stosu po wykonaniu wszystkich operacji
	nodeHeap.reset();
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

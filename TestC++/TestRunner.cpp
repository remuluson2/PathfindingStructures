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
	MemoryReader::GetInstance()->GetMemoryStatus();
	for (int i = 0; i < 100; i++) {
		RunCase(BEST, SINGLECHILDHEAP, 5000);
		RunCase(BEST, BINARYHEAP, 5000);
	}

	for (int i = 0; i < 100; i++) {
		RunCase(WORST, SINGLECHILDHEAP, 5000);
		RunCase(WORST, BINARYHEAP, 5000);
	}

	for (int i = 0; i < 100; i++) {
		RunCase(RANDOM, SINGLECHILDHEAP, 5000);
		RunCase(RANDOM, BINARYHEAP, 5000);
	}
}

void PathfindingTester::TestRunner::RunCases(int caseIndex, int structureIndex, int nodeNumber, int timesToRun) {

}

void PathfindingTester::TestRunner::RunCase(int caseIndex, int structureIndex, int nodeNumber) {
	auto start = std::chrono::high_resolution_clock::now();
	std::cout << "\nRunning Case!\n";
	SimulateOperation(caseIndex, structureIndex, nodeNumber);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "Case took " << duration.count() << "ms to run.";
	ResultSaver::GetInstance()->executionTime = duration.count();
	ResultSaver::GetInstance()->SaveResultToFile(structureIndex, caseIndex, nodeNumber);
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
		MemoryReader::GetInstance()->GetMemoryStatus();
		nodeHeap->Clear();
		break;
	case WORST:
		std::cout << "\nTesting WORST case\n";
		for (int i = 0; i < nodeNumber; i++) {
			nodeHeap->AddNode(Node(0, 0, i));
		}
		MemoryReader::GetInstance()->GetMemoryStatus();
		nodeHeap->Clear();
		break;
	case BEST:
		std::cout << "\nTesting BEST case\n";
		for (int i = 0; i < nodeNumber; i++) {
			nodeHeap->AddNode(Node(0, 0, nodeNumber - i));
		}
		MemoryReader::GetInstance()->GetMemoryStatus();
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

Node PathfindingTester::TestRunner::GeneratePoint(int index)
{
	srand(15112024 + index);
	Node result;
	result.cost = rand() % 1000;
	result.x = 0;
	result.y = 0;
	return result;
}

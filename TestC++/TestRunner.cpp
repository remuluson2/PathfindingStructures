#pragma once
#include "TestRunner.h"
enum TestCases {
	RANDOM,
	WORST,
	BEST
};
void PathfindingTester::TestRunner::RunTest()
{
	std::remove("result.txt");

	std::cout << "\n\nStarting test!\n";
	MemoryReader::GetInstance()->GetMemoryStatus();

	std::cout << "\nRunning Case!\n";
	//RunCase(2, 2, 10000);
	Sleep(1000);
	MemoryReader::GetInstance()->GetMemoryStatus();
	//SaveResult(std::to_string(MemoryReader::GetInstance()->GetMemoryChange()));
	//SaveResult(std::to_string(MemoryReader::GetInstance()->GetMemoryChangePhys()));

	std::cout << "\nRunning Case!\n";
	//RunCase(1, 2, 10000);
	Sleep(1000);
	MemoryReader::GetInstance()->GetMemoryStatus();
	//SaveResult(std::to_string(MemoryReader::GetInstance()->GetMemoryChange()));
	//SaveResult(std::to_string(MemoryReader::GetInstance()->GetMemoryChangePhys()));

	std::cout << "\nRunning Case!\n";
	//RunCase(0, 2, 10000);
	Sleep(2000);
	MemoryReader::GetInstance()->GetMemoryStatus();
	Sleep(5000);
	MemoryReader::GetInstance()->GetMemoryStatus();
	Sleep(20000);
	MemoryReader::GetInstance()->GetMemoryStatus();
	//SaveResult(std::to_string(MemoryReader::GetInstance()->GetMemoryChange()));
	//SaveResult(std::to_string(MemoryReader::GetInstance()->GetMemoryChangePhys()));

}

void PathfindingTester::TestRunner::RunCase(int caseIndex, int structureIndex, int nodeNumber)
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
	MemoryReader::GetInstance()->GetMemoryStatus();
	std::cout << "\nReseting the heap holder!\n";
	nodeHeap.reset();
	MemoryReader::GetInstance()->GetMemoryStatus();
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

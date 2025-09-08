#pragma once
#include "TestRunner.h"
#include <filesystem>
namespace fs = std::filesystem;
void TestRunner::RunTest()
{
	srand(time(NULL));
	int const startvalue = 0;
	int const iterations = 10;
	int const multiplayer = 1000;
	int const targetDatapointNum = 100;
	//Test

	if (!CheckIfTestCaseFilesArePresent("SINGLEHEAPBEST")) {
		for (int i = 1; i <= iterations; i++) {
			RunCases(BEST, SINGLECHILDHEAP, i * multiplayer + startvalue, targetDatapointNum);
		}
		return;
	}
	if (!CheckIfTestCaseFilesArePresent("SINGLEHEAPWORST")) {
		for (int i = 1; i <= iterations; i++) {
			RunCases(WORST, SINGLECHILDHEAP, i * multiplayer + startvalue, targetDatapointNum);
		}
		return;
	}
	if (!CheckIfTestCaseFilesArePresent("BINARYHEAPBEST")) {
		for (int i = 1; i <= iterations; i++) {
			RunCases(BEST, BINARYHEAP, i * multiplayer + startvalue, targetDatapointNum);
		}
		return;
	}
	if (!CheckIfTestCaseFilesArePresent("BINARYHEAPWORST")) {
		for (int i = 1; i <= iterations; i++) {
			RunCases(WORST, BINARYHEAP, i * multiplayer + startvalue, targetDatapointNum);
		}
		return;
	}

	if (!CheckIfTestCaseFilesArePresent("BINARYHEAPRANDOM")) {
		for (int i = 1; i <= iterations; i++) {
			RunCases(RANDOM, BINARYHEAP, i * multiplayer + startvalue, targetDatapointNum);
		}
		return;
	}

	if (!CheckIfTestCaseFilesArePresent("SINGLEHEAPRANDOM")) {
		for (int i = 1; i <= iterations; i++) {
			RunCases(RANDOM, SINGLECHILDHEAP, i * multiplayer + startvalue, targetDatapointNum);
		}
		return;
	}
}

void TestRunner::RunCases(TestCases caseIndex, int structureIndex, int numberOfInsertedNodes, int timesToRun) {
	//Wynik z poprzedniego uruchomienia jest usuwany je¿eli istnieje.
	std::string resultfilename = "results/result" + StructureIndexToName(structureIndex) + CaseIndexToName(caseIndex) + std::to_string(numberOfInsertedNodes) + ".csv";
	std::remove(resultfilename.c_str());
	for (int i = 1; i <= timesToRun; i++) {
		RunCase(caseIndex, structureIndex, numberOfInsertedNodes, i);
	}
}

void TestRunner::RunCase(TestCases caseIndex, int structureIndex, int mapSize, int index) {
	auto generatedMap = GeneratingMap(caseIndex, mapSize);
	auto start = std::chrono::high_resolution_clock::now();
	SimulateOperation(caseIndex, structureIndex, &generatedMap);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	ResultSaver::GetInstance()->executionTime = duration.count();
	ResultSaver::GetInstance()->SaveResultToFile(structureIndex, caseIndex, mapSize, index, mapSize, MemoryReader::GetInstance()->GetTotalMemoryUsedByProgram(), MemoryReader::GetInstance()->GetTotalPhysicalMemoryUsedByProgram());
	generatedMap.ResetVisitFlags();
}

void TestRunner::SimulateOperation(TestCases caseIndex, int structureIndex, GeneratingMap* map)
{
	std::unique_ptr<HeapBase> nodeHeap;
	//W zale¿nosci od parametrow, zostaje utworzona odpowiednia struktura we wskazniku nodeHeap.
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
		break;
	case WORST:
		break;
	case BEST:
		break;
	}
	//Deallokacja wezlow znajdujacych sie na stosie
	nodeHeap->Clear();
	//deallokacja stosu po wykonaniu wszystkich operacji
	nodeHeap.reset();
}

void TestRunner::SaveResult(std::string text)
{
	std::ofstream MyFile("result.txt", std::ios_base::app);

	// Write to the file
	MyFile << text << "\n";

	// Close the file
	MyFile.close();
}

std::string TestRunner::CaseIndexToName(int caseIndex)
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

std::string TestRunner::StructureIndexToName(int structureIndex)
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

bool TestRunner::CheckIfTestCaseFilesArePresent(std::string fileName)
{
	std::string path = "results/";
	for (const auto& entry : fs::directory_iterator(path))
	{
		if (entry.path().string().find(fileName) != std::string::npos) {
			return true;
		}
	}
	return false;
}

Node TestRunner::GeneratePoint(int index)
{
	Node result;
	result.cost = rand() % 1000;
	result.x = 0;
	result.y = 0;
	return result;
}

#include "ResultSaver.h"

ResultSaver* ResultSaver::instancePointer = nullptr;

ResultSaver::ResultSaver()
{
	numOfOperations = 0;
	executionTime = 0;
	memoryUsed = 0;
	numberOfSwaps = 0;
}

ResultSaver::~ResultSaver()
{
	delete instancePointer;
}

ResultSaver* ResultSaver::GetInstance()
{
	if (instancePointer == nullptr) {
		instancePointer = new ResultSaver();
	}
	return instancePointer;
}

void ResultSaver::SaveResultToFile(int structIndex, int caseIndex, int mapSize, int index, int memoryUsed, int memoryUsed2)
{
	std::string structName;
	std::string caseName;
	switch (structIndex) {
	case 1:
		structName = "SINGLEHEAP";
		break;
	case 2:
		structName = "BINARYHEAP";
		break;
	}
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
	std::ofstream resultFile("results/result" + structName + caseName + std::to_string(mapSize) + ".csv", std::ios_base::app);

	// Write to the file
	resultFile << index << "," << executionTime << "," << numOfOperations << "," << numberOfSwaps << "," << memoryUsed << "," << memoryUsed2 << "\n";

	// Close the file
	resultFile.close();
	ClearResult();
}

void ResultSaver::ClearResult()
{
	numOfOperations = 0;
	executionTime = 0;
	memoryUsed = 0;
	numberOfSwaps = 0;
}

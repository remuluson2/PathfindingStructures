#pragma once
#include <fstream>
#include <string>
namespace PathfindingTester {
	class ResultSaver
	{
	private:
		static ResultSaver* instancePointer;
		ResultSaver();
		~ResultSaver();
	public:
		ResultSaver(const ResultSaver& obj) = delete;
		static ResultSaver* GetInstance();
		unsigned int numOfOperations;
		unsigned int executionTime;
		unsigned int memoryUsed;
		unsigned int numberOfSwaps;
		void SaveResultToFile(int structIndex, int caseIndex, int nodeNumber, int index, int nodenum);
		void ClearResult();
	};
}

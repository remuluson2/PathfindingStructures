#pragma once
#pragma comment(lib,"psapi")
#include "Windows.h"
#include "psapi.h"
#include <iostream>
#include <fstream>
#include <strsafe.h>
namespace PathfindingTester {
	class MemoryReader
	{
	private:
		double lastState;
		double lastStatePhys;
		PROCESS_MEMORY_COUNTERS_EX pmc;
		static MemoryReader* instancePointer;
		MemoryReader();
		~MemoryReader();
		void ErrorExit(LPCTSTR lpszFunction);
		int byteCounter;
	public:
		MemoryReader(const MemoryReader& obj) = delete;
		static MemoryReader* GetInstance();
		void GetMemoryStatus();
		SIZE_T GetTotalMemoryUsedByProgram();
		SIZE_T GetTotalPhysicalMemoryUsedByProgram();
		SIZE_T GetMemoryChange();
		SIZE_T GetMemoryChangePhys();
		void LogAllocateMemory(int value);
		void LogFreeMemory(int value);
		int GetMemorySinceLast();
	};
}

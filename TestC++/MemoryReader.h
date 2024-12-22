#pragma once
#pragma comment(lib,"psapi")
#include "Windows.h"
#include "psapi.h"
#include <iostream>
namespace PathfindingTester {
	class MemoryReader
	{
	private:
		DWORDLONG lastState;
		DWORDLONG lastStatePhys;
		PROCESS_MEMORY_COUNTERS_EX pmc;
		static MemoryReader* instancePointer;
		MemoryReader();
	public:
		MemoryReader(const MemoryReader& obj) = delete;
		static MemoryReader* GetInstance();
		void GetMemoryStatus();
		SIZE_T GetTotalMemoryUsedByProgram();
		SIZE_T GetTotalPhysicalMemoryUsedByProgram();
		SIZE_T GetMemoryChange();
		SIZE_T GetMemoryChangePhys();
	};
}

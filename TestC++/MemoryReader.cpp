#include "MemoryReader.h"
using namespace PathfindingTester;

MemoryReader* MemoryReader::instancePointer = nullptr;

MemoryReader::MemoryReader()
{
	lastState = 0;
	lastStatePhys = 0;
	GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
}

MemoryReader* MemoryReader::GetInstance()
{
	if (instancePointer == nullptr) {
		instancePointer = new MemoryReader();
	}
	return instancePointer;
}

void MemoryReader::GetMemoryStatus()
{
	auto result = GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
	if (result == 0) {
		std::cout << "Error when reading process memory status!! Error code: " << GetLastError();
		
	}

	SIZE_T virtualMemUsedByMe = pmc.PrivateUsage;

	SIZE_T physMemUsedByMe = pmc.WorkingSetSize;

	std::cout << "\n\nVirtual memory used by program: " << virtualMemUsedByMe << " : " << (virtualMemUsedByMe - lastState) <<
		"\n\nPhysical memory used by program: " << physMemUsedByMe << " : " << (physMemUsedByMe - lastStatePhys) << "\n";
	lastState = pmc.PrivateUsage;
	lastStatePhys = pmc.WorkingSetSize;
}

SIZE_T PathfindingTester::MemoryReader::GetTotalMemoryUsedByProgram()
{
	GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
	return pmc.PrivateUsage;
}

SIZE_T PathfindingTester::MemoryReader::GetTotalPhysicalMemoryUsedByProgram()
{
	GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
	return pmc.WorkingSetSize;
}

SIZE_T PathfindingTester::MemoryReader::GetMemoryChange()
{
	return GetTotalMemoryUsedByProgram() - lastState;
}

SIZE_T PathfindingTester::MemoryReader::GetMemoryChangePhys()
{
	return GetTotalPhysicalMemoryUsedByProgram() - lastStatePhys;
}

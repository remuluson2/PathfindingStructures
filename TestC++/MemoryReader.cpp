#include "MemoryReader.h"
using namespace PathfindingTester;

MemoryReader* MemoryReader::instancePointer = nullptr;

MemoryReader::MemoryReader()
{
	lastState = 0;
	lastStatePhys = 0;
	byteCounter = 0;
	GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(&pmc));
}

PathfindingTester::MemoryReader::~MemoryReader()
{
	delete instancePointer;
}

void PathfindingTester::MemoryReader::ErrorExit(LPCTSTR lpszFunction)
{
	// Retrieve the system error message for the last-error code

	LPVOID lpMsgBuf;
	LPVOID lpDisplayBuf;
	DWORD dw = GetLastError();

	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		dw,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf,
		0, NULL);

	// Display the error message and exit the process

	lpDisplayBuf = (LPVOID)LocalAlloc(LMEM_ZEROINIT,
		(lstrlen((LPCTSTR)lpMsgBuf) + lstrlen((LPCTSTR)lpszFunction) + 40) * sizeof(TCHAR));
	StringCchPrintf((LPTSTR)lpDisplayBuf,
		LocalSize(lpDisplayBuf) / sizeof(TCHAR),
		TEXT("%s failed with error %d: %s"),
		lpszFunction, dw, lpMsgBuf);
	MessageBox(NULL, (LPCTSTR)lpDisplayBuf, TEXT("Error"), MB_OK);

	LocalFree(lpMsgBuf);
	LocalFree(lpDisplayBuf);
	ExitProcess(dw);
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
		std::cout << "Error when reading process memory status!!";

		ErrorExit(TEXT("GetProcessMemoryInfo"));
	}

	double virtualMemUsedByMe = (double)pmc.PrivateUsage / 1024.0;

	double physMemUsedByMe = (double)pmc.WorkingSetSize / 1024.0;

	std::cout << "\n\nVirtual memory used by program: " << virtualMemUsedByMe << " : " << (virtualMemUsedByMe - lastState) <<
		"\nPhysical memory used by program: " << physMemUsedByMe << " : " << (physMemUsedByMe - lastStatePhys) << "\n";
	lastState = virtualMemUsedByMe;
	lastStatePhys = physMemUsedByMe;
}

SIZE_T PathfindingTester::MemoryReader::GetTotalMemoryUsedByProgram()
{
	GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
	return pmc.PrivateUsage;
}

SIZE_T PathfindingTester::MemoryReader::GetTotalPhysicalMemoryUsedByProgram()
{
	GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
	return pmc.PeakWorkingSetSize;
}

SIZE_T PathfindingTester::MemoryReader::GetMemoryChange()
{
	return GetTotalMemoryUsedByProgram() - lastState;
}

SIZE_T PathfindingTester::MemoryReader::GetMemoryChangePhys()
{
	return GetTotalPhysicalMemoryUsedByProgram() - lastStatePhys;
}
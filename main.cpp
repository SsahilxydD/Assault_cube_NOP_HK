#include <iostream>
#include <Windows.h>
using namespace std;

DWORD GetProcId(const char* procName)
{
	HWND acWindow = FindWindow(nullptr, "AssaultCube");

	DWORD processId;
	GetWindowThreadProcessId(acWindow, &processId);

	return processId;
}

int main()
{
	const char* dllPath = "D:\\Visual Studio Projects\\ac\\bin\\ac.dll";
	const char* procName = "ac_client.exe";

	DWORD processId = GetProcId(procName);

	HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, NULL, processId);

	void* spaceForDllPath = VirtualAllocEx(hProc, nullptr, strlen(dllPath), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

	WriteProcessMemory(hProc, spaceForDllPath, dllPath, strlen(dllPath), nullptr);

	HANDLE hThread = CreateRemoteThread(hProc, NULL, NULL, (LPTHREAD_START_ROUTINE)LoadLibraryA, spaceForDllPath, NULL, nullptr);

	CloseHandle(hThread);
	CloseHandle(hProc);

	
}
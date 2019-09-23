#include <iostream>
#include "GameCodeApp.h"

using namespace std;

GameCodeApp::GameCodeApp()
{

}

bool GameCodeApp::CheckMemory(const DWORDLONG physicalRAMNeeded, const DWORDLONG virtualRAMNeeded) {
	MEMORYSTATUSEX status;
	GlobalMemoryStatusEx(&status);
	if (status.ullTotalPhys < physicalRAMNeeded) {
		/* You don't have enough physical memory.*/
		cout << "CheckMemory Failure: Not enough physical memory.";
		return false;
	}
	//Check for enough free memory.
	if (status.ullAvailVirtual < virtualRAMNeeded) {
		// You don't have enough virtual memory available.
		cout << "CheckMemory Failure: Not enough virtual memory.";
		return false;
	}
	char *buff = new char[virtualRAMNeeded];
	if (buff)
		delete[] buff;
	else {
		cout << "CheckMemory Failure: Not enough contiguous memory.";
		return false;
	}
}

DWORD GameCodeApp::ReadCPUSpeed() {
	DWORD BufSize = sizeof(DWORD);
	DWORD dwMHz = 0;
	DWORD type = REG_DWORD;
	HKEY hKey;
	// open the key where the proc speed is hidden:
	long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0",
		0, KEY_READ, &hKey);
	if (lError == ERROR_SUCCESS) {
		// query the key:
		RegQueryValueEx(hKey, "MHz", NULL, &type, (LPBYTE)&dwMHz,
			&BufSize);
	}
	return dwMHz;
}

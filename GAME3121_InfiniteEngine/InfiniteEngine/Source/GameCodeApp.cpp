#include "GameCodeApp.h"
#include <iostream>

using namespace std;

GameCodeApp::GameCodeApp()
{
	
}

bool GameCodeApp::CheckMemory() {
	MEMORYSTATUSEX status;
	GlobalMemoryStatusEx(&status);
	//cout << status.ullAvailPhys;
	if (!status.ullAvailPhys) {
		/* You don't have enough physical memory.*/
		cout << "CheckMemory Failure: Not enough physical memory.";
		return false;
	}
	else
		cout << "Available physical memory: " << status.ullAvailPhys / 1024 << " KB\n";

	//Check for enough free memory.
	if (!status.ullAvailVirtual) {
		// You don't have enough virtual memory available.
		cout << "CheckMemory Failure: Not enough virtual memory.";
		return false;
	}
	else
		cout << "Available virtual memory: " << status.ullAvailVirtual / 1024 << " KB\n";

}
#include <iostream>
#include "GameCodeApp.h"

using namespace std;

GameCodeApp::GameCodeApp()
{

}

DWORD GameCodeApp::ReadCPUSpeed() {
	DWORD BufSize = sizeof(DWORD);
	DWORD dwMHz = 0;
	DWORD type = REG_DWORD;
	DWORD type2 = REG_SZ;
	char processor[1023];
	HKEY hKey;
	DWORD charSize = sizeof(processor);
	// open the key where the proc speed is hidden:
	long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0",
		0, KEY_READ, &hKey);
	if (lError == ERROR_SUCCESS) {
		// query the key:
		RegQueryValueEx(hKey, "~MHz", NULL, &type, (LPBYTE)&dwMHz,
			&BufSize);
		RegQueryValueEx(hKey, "ProcessorNameString", NULL, &type2, (LPBYTE)&processor,
			&charSize);
	}

	cout << "CPU Speed: " << dwMHz << " MHz\n";
	cout << "Processor: " << processor << "\n";
	return dwMHz;
}

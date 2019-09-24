#include "GameCodeApp.h"
using namespace std;

GameCodeApp::GameCodeApp()
{
	mName = LPCSTR("Infinite Engine");
	Initialise();
}

void GameCodeApp::Initialise()
{
	if (IsOnlyInstance(mName))
	{
		cout << "This is the only instance of window " << mName << endl;
	}
	else
	{
		cout << "There is another instance of window " << mName << endl;
	}

	


	if (CheckStorage(300000000))
	{
		cout << "The computer has sufficient storage space." << endl;
	}
	else
	{
		cout << "The computer does not have sufficient storage space." << endl;
	}

	DWORD test = ReadCPUSpeed();
	cout << "CPU SPEED = " << test << " MHz" << endl;

	//system("PAUSE");

	if (CheckMemory(1, 1))
	{
		cout << "There is enough memory available.\n";
	}
	else
	{
		cout << "There isn't enough memory available.\n";
	}
}

bool GameCodeApp::IsOnlyInstance(LPCTSTR gameTitle) {
	HANDLE handle = CreateMutex(NULL, TRUE, gameTitle);
	if (GetLastError() != ERROR_SUCCESS) {
		HWND hWnd = FindWindow(gameTitle, NULL);
		if (hWnd) {
			// An instance of your game is already running.
			ShowWindow(hWnd, SW_SHOWNORMAL);
			SetFocus(hWnd);
			SetForegroundWindow(hWnd);
			SetActiveWindow(hWnd);
			return false;
		}
	}
	return true;
}

bool GameCodeApp::CheckStorage(const DWORDLONG diskSpaceNeeded) {
	// Check for enough free disk space on the current disk.
	int const drive = _getdrive();
	struct _diskfree_t diskfree;
	_getdiskfree(drive, &diskfree);
	unsigned __int64 const neededClusters = diskSpaceNeeded /
		(diskfree.sectors_per_cluster *
			diskfree.bytes_per_sector);

	if (diskfree.avail_clusters < neededClusters) {
		// if you get here you don’t have enough disk space!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		//GCC_ERROR("CheckStorage Failure: Not enough physical storage.");
//#pragma GCC error "CheckStorage Failure: Not enough physical storage."
		return false;
	}
	return true;
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
		//cout << "ERROR SUCCESS" << endl;
		// query the key:
		RegQueryValueEx(hKey, "~MHz", NULL, &type, (LPBYTE)&dwMHz,
			&BufSize);
	}
	return dwMHz;
}

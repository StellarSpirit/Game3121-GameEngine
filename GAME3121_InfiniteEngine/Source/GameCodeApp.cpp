#if defined(_DEBUG)
# define GCC_NEW new(_NORMAL_BLOCK,__FILE__, __LINE__)
#else
# define GCC_NEW new
//# define GCC_ERROR(str) do {void sizeof(str)} while (0)
#endif

#include "GameCodeApp.h"



DWORD GameCodeApp::ReadCPUSpeed() {
	DWORD BufSize = sizeof(DWORD);
	DWORD dwMHz = 0;
	DWORD type = REG_DWORD;
	HKEY hKey;
	// open the key where the proc speed is hidden:
	long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
		"HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0",
		0,
		KEY_READ,
		&hKey);
	if (lError == ERROR_SUCCESS) {
		// query the key:
		RegQueryValueEx(hKey,
			"MHz",
			NULL,
			&type,
			(LPBYTE)&dwMHz,
			&BufSize);
	}
	return dwMHz;
}
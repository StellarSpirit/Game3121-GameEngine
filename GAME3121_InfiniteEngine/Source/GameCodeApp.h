#pragma once
#include "windows.h"
#include <stdio.h>
#include <direct.h>
#include <stdlib.h>
#include <ctype.h>
#include <errors.h>

class GameCodeApp
{
	//bool IsOnlyInstance(LPCTSTR gameTitle);
	//bool CheckStorage(const DWORDLONG diskSpaceNeeded);
	//bool CheckMemory(const DWORDLONG physicalRAMNeeded, const DWORDLONG virtualRAMNeeded);
	DWORD ReadCPUSpeed();
};
#pragma once

#include "Windows.h"

class GameCodeApp
{
public:

	GameCodeApp();

	bool CheckMemory(const DWORDLONG physicalRAMNeeded, const DWORDLONG virtualRAMNeeded);
	DWORD ReadCPUSpeed();
};

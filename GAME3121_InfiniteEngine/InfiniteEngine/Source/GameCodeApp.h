#pragma once
#include "Windows.h"
#include <stdio.h>
#include <direct.h>
#include "iostream"

class GameCodeApp
{
public:
	LPCSTR mName;

	GameCodeApp();

	void Initialise();
	bool IsOnlyInstance(LPCTSTR gameTitle);
	bool CheckStorage(const DWORDLONG diskSpaceNeeded);
	bool CheckMemory(const DWORDLONG physicalRAMNeeded, const DWORDLONG virtualRAMNeeded);
	DWORD ReadCPUSpeed();
};
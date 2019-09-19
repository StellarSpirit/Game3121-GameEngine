#pragma once
#include "Windows.h"
#include <stdio.h>
#include <direct.h>

class GameCodeApp
{
public:
	LPCSTR mName;

	GameCodeApp();

	bool IsOnlyInstance(LPCTSTR gameTitle);
	bool CheckStorage(const DWORDLONG diskSpaceNeeded);
};
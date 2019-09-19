#pragma once
#include "Windows.h"

class GameCodeApp
{
public:
	LPCSTR mName;

	GameCodeApp();

	bool IsOnlyInstance(LPCTSTR gameTitle);
};
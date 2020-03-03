#pragma once
#include "Windows.h"
#include <stdio.h>
#include <direct.h>
#include "iostream"
#include "SceneManager.h"


class GameCodeApp
{
public:
	LPCSTR mName;

	SceneManager mSceneManager;

	GameCodeApp();

	void Initialise();
	bool IsOnlyInstance(LPCTSTR gameTitle);
	bool CheckStorage(const DWORDLONG diskSpaceNeeded);
	bool CheckMemory();
	DWORD ReadCPUSpeed();
	void RunEngine();
	void Update(float deltaTime);

	

};
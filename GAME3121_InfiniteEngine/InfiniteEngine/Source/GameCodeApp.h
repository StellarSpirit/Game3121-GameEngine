#pragma once
#include "Windows.h"
#include <stdio.h>
#include <direct.h>
#include "iostream"
#include "SceneManager.h"
#include "RenderComponentInterface.h"


class GameCodeApp
{

public:
	GameCodeApp();
	LPCSTR mName;

	SceneManager mSceneManager;
	SceneManager* mpSceneManager;

	RenderComponentInterface mRenderInterface;

	

	void Initialise();
	bool IsOnlyInstance(LPCTSTR gameTitle);
	bool CheckStorage(const DWORDLONG diskSpaceNeeded);
	bool CheckMemory();
	DWORD ReadCPUSpeed();
	void RunEngine();
	void Update(float deltaTime, sf::RenderWindow* window);

	

};
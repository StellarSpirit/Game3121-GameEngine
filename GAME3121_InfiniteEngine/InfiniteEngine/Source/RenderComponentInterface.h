#pragma once
#include "SceneManager.h"
#include "RenderComponent.h"
#include "TransformComponent.h"
#include <SFML/Graphics.hpp>

class RenderComponentInterface
{
private:
	
	vector<Actor*> mRenderActors;
	//sf::RenderWindow mainWindow;
public:
	RenderComponentInterface() { mpSceneManager = nullptr; }
	RenderComponentInterface(SceneManager* pSceneManager);
	void Update(float dt, sf::RenderWindow* window);
	SceneManager* mpSceneManager;
};
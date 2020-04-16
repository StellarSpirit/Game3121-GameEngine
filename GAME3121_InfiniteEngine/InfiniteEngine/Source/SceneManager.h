#pragma once
#include "Actor.h"
#include <vector>
using namespace std;

class SceneManager
{
private:
	vector<Actor*> mAllActors;
	void AddActor(Actor* newActor) { mAllActors.push_back(newActor); }
public:
	SceneManager();
	~SceneManager();
	void AddActorToScene();
	void AddActorToScene(string _spriteTextureImagePath, sf::Vector2f _positionVector);
	vector<Actor*> getAllActors() { return mAllActors; }
	vector<Actor*> GetActorsWithRenderComponent();
	//vector<Actor*> GetAllActorsWithComponent(string componentRequired);
	//vector<Actor*> GetAllActorsWithComponents(string componentRequiredA, string componentRequiredB);
};


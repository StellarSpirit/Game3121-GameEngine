#include "SceneManager.h"



SceneManager::SceneManager()
{
	mAllActors = vector<Actor*>();
}


SceneManager::~SceneManager()
{
}

void SceneManager::AddActorToScene()
{
	Actor* newActor = new Actor();
	AddActor(newActor);
}

void SceneManager::AddActorToScene(string _spriteTextureImagePath, sf::Vector2f _positionVector)
{
	Actor* newActor = new Actor();
	newActor->AddRenderComponent(_spriteTextureImagePath);
	newActor->AddTransformComponent(_positionVector);
	AddActor(newActor);
}

vector<Actor*> SceneManager::GetActorsWithRenderComponent()
{
	vector<Actor*> returnActors = vector<Actor*>();
	for (auto x : mAllActors)
	{
		if (x->GetRenderComponent() != nullptr && x->GetTransformComponent() != nullptr)
		{
			Actor* xref = x;
			returnActors.push_back(xref);
		}
		return returnActors;
	}

	return vector<Actor*>();
}

//vector<Actor*> SceneManager::GetAllActorsWithComponent(string componentRequired)
//{
//	vector<Actor*> returnActors = vector<Actor*>();
//	for (auto x : mAllActors)
//	{
//		if (x.HasComponent(componentRequired))
//		{
//			Actor* xref = &x;
//			returnActors.push_back(xref);
//		}
//		if (returnActors.size > 0)
//			return returnActors;
//	}
//	return vector<Actor*>();
//}

//vector<Actor*> SceneManager::GetAllActorsWithComponents(string componentRequiredA, string componentRequiredB)
//{
//	/*vector<Actor*> returnActors = vector<Actor*>();
//	for (auto x : mAllActors)
//	{
//		if (x.HasComponent(componentRequiredA) && x.HasComponent(componentRequiredB))
//		{
//			Actor* xref = &x;
//			returnActors.push_back(xref);
//		}
//		if (returnActors.size > 0)
//			return returnActors;
//	}
//	return vector<Actor*>();*/
//}

#pragma once
#include "BaseComponent.h"
#include "RenderComponent.h"
#include "TransformComponent.h"
#include <vector>


class Actor
{
private:
	std::vector<BaseComponent> mComponents;
	RenderComponent* mpRenderComponent;
	TransformComponent* mpTransformComponent;
public:
	Actor() 
	{
		mpRenderComponent = nullptr;
		mpTransformComponent = nullptr;
	}
	~Actor() {};
	template <typename T> void AddComponent(T componentToAdd) { mComponents.push_back(componentToAdd); }
	bool HasComponent(string ComponentName) {
		for (auto x : mComponents)
		{
			if (x.GetName() == ComponentName)
				return true;
		}
		return false;
	};
	BaseComponent* GetComponent(string ComponentName) {
		for (auto x : mComponents)
		{
			if (x.GetName() == ComponentName)
			{
				BaseComponent* returnValue = &x;
				return returnValue;
			}
		}
		return NULL;
	}
	void AddRenderComponent(string TexturePath)
	{
		mpRenderComponent = new RenderComponent(TexturePath);
	}
	RenderComponent* GetRenderComponent()
	{
		return mpRenderComponent;
	}
	void AddTransformComponent(sf::Vector2f _position)
	{
		mpTransformComponent = new TransformComponent(_position);
	}
	TransformComponent* GetTransformComponent()
	{
		return mpTransformComponent;
	}
};


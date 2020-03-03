#pragma once
#include "BaseComponent.h"
#include <vector>


class Actor
{
private:
	std::vector<BaseComponent> mComponents;
public:
	Actor();
	~Actor();
	template <typename T> void AddComponent(T componentToAdd) { mComponents.push_back(componentToAdd); }
	
};


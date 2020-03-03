#pragma once
#include "BaseComponent.h"
#include <SFML/System.hpp>

using namespace std;

class TransformComponent : public BaseComponent
{
private:
	sf::Vector2f position;
public:
	TransformComponent(sf::Vector2f _position) {
		componentName = "TRANSFORM";
		position = _position;
	}
	void SetPosition(sf::Vector2f newPosition) { position = newPosition; }
	sf::Vector2f GetPosition() { return position; }
	
};
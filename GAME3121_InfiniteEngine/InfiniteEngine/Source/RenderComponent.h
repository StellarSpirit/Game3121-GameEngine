#pragma once
#include <SFML/Graphics.hpp>
#include "BaseComponent.h"
#include <string>
using namespace std;

/*sf::Texture splashScreenImage;
splashScreenImage.loadFromFile("../Assets/Images/IELogoBlotches.png");
sf::Sprite splashScreenSprite;
splashScreenSprite.setTexture(splashScreenImage);*/

class RenderComponent : public BaseComponent
{
private:
	sf::Texture mTexture;
public:
	sf::Sprite mSprite;
	RenderComponent(string TexturePath){
		componentName = "RENDER";
		mTexture.loadFromFile(TexturePath);
		mSprite.setTexture(mTexture);
		}
};
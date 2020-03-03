#include <SFML/Graphics.hpp>
#include "GameCodeApp.h"

int main()
{
	GameCodeApp gGameCodeApp = GameCodeApp();
	/*sf::Clock clock;

	sf::RenderWindow window(sf::VideoMode(800, 600), "INFINITE ENGINE");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	sf::Time splashScreenDelay = sf::seconds(5.0f);

	sf::Texture splashScreenImage;
	splashScreenImage.loadFromFile("../Assets/Images/IELogoBlotches.png");
	sf::Sprite splashScreenSprite;
	splashScreenSprite.setTexture(splashScreenImage);

	while (window.isOpen())
	{
		sf::Event event;
		
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		
		
		window.clear();
		window.draw(shape);
		if (clock.getElapsedTime() < splashScreenDelay)
			window.draw(splashScreenSprite);
		window.display();
	}*/

	

	
	return 0;
}
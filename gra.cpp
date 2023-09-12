#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Window.hpp>
#include <iostream>

int main ()
{
	sf::RenderWindow window(sf::VideoMode(800, 700), "Okno zycia");

	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	if (playerTexture.loadFromFile("spritesheet-org.png"))
	{
		std::cout << "Player image loaded!" << std::endl;
		playerSprite.setTexture(playerTexture);

		int XIndex = 0;
		int YIndex = 0;

		playerSprite.scale(sf::Vector2f(0.5, 0.5));
		playerSprite.setTextureRect(sf::IntRect(XIndex * 256, YIndex * 256, 256, 256)); 
		
	}
	else
	{
		std::cout << "Player image failed to load!" << std::endl;
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			/* sooo this is shit bcoz after about 0.25s it's registrating you're holding the key so there's an ugly pause >:/
			if (event.type == sf::Event::KeyPressed)
			{
				if(event.key.code == sf::Keyboard::S)
				{
					sf::Vector2f position = playerSprite.getPosition();
					playerSprite.setPosition(position + sf::Vector2f(0, 10));

				}

			} */
		}

		sf::Vector2f position = playerSprite.getPosition();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			playerSprite.setPosition(position + sf::Vector2f(0, -1));

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			playerSprite.setPosition(position + sf::Vector2f(0, 1));

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			playerSprite.setPosition(position + sf::Vector2f(-1, 0));

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			playerSprite.setPosition(position + sf::Vector2f(1, 0));

		window.clear(sf::Color::Black);
		window.draw(playerSprite);	
		window.display();
	}

	return 0;
}
//

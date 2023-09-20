#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Window.hpp>
#include <iostream>
#include <vector>
#include <math.h>

// wektor przemieszczenia z pitagorasa
sf::Vector2f NormalizeVector(sf::Vector2f vector)
{
	// magnitude
	float m = std::sqrt(vector.x * vector.x + vector.y * vector.y);

	sf::Vector2f normalizedVector;

	normalizedVector.x = vector.x / m;
	normalizedVector.y = vector.y / m;

	return normalizedVector;
}

int main ()
{	
	// WINDOW INITIALIZE
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Okno zycia");

	// BULLET INITIALIZE
	std::vector<sf::RectangleShape> bullets;
	float bulletSpeed = 0.5f;

	// ENEMY INITIALIZE
	sf::Texture enemyTexture;
	sf::Sprite enemySprite;

	// ENEMY LOAD
	if (enemyTexture.loadFromFile("enemy.png"))
	{
		std::cout << "Enemy image loaded!" << std::endl;
		enemySprite.setTexture(enemyTexture);
		enemySprite.setPosition(sf::Vector2f(400,100));

		int XIndex = 0;
		int YIndex = 0;

		enemySprite.scale(sf::Vector2f(2, 2));
		enemySprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64)); 
		
	}
	else
	{
		std::cout << "Enemy image failed to load!" << std::endl;
	}

	// PLAYER INITIALIZE
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	// PLAYER LOAD
	if (playerTexture.loadFromFile("spritesheet-org.png"))
	{
		std::cout << "Player image loaded!" << std::endl; 
		playerSprite.setTexture(playerTexture);

		int XIndex = 0;
		int YIndex = 0;

		playerSprite.scale(sf::Vector2f(0.5, 0.5));
		playerSprite.setTextureRect(sf::IntRect(XIndex * 256, YIndex * 256, 256, 256)); 
		playerSprite.setPosition(sf::Vector2f(1650, 800));

	}
	else
	{
		std::cout << "Player image failed to load!" << std::endl;
	}

	// SETTING POSITION AND DIRECTION OF THE BULLET


	// sf::Vector2f bulletDirection = enemySprite.getPosition() - bullet.getPosition();
	// bulletDirection = NormalizeVector(bulletDirection);

	// UPDATE LOOP
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

		// BULLET MOVEMENT
		// bullet.setPosition(bullet.getPosition() + bulletDirection * bulletSpeed);

		sf::Vector2f position = playerSprite.getPosition();

		// KEYBOARD MOVEMENT
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			playerSprite.setPosition(position + sf::Vector2f(0, -1));

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			playerSprite.setPosition(position + sf::Vector2f(0, 1));

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			playerSprite.setPosition(position + sf::Vector2f(-1, 0));

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			playerSprite.setPosition(position + sf::Vector2f(1, 0));

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			bullets.push_back(sf::RectangleShape(sf::Vector2f(50, 25))); // push back = add

			int i = bullets.size() - 1;
			bullets[i].setPosition(playerSprite.getPosition()); // set pos of the bullet

			sf::Vector2f bulletDirection = enemySprite.getPosition() - bullets[i].getPosition();
			bulletDirection = NormalizeVector(bulletDirection); // normalizing the vector

		}

		// WINDOW DRAW
		window.clear(sf::Color::Black);
		window.draw(playerSprite);
		window.draw(enemySprite);
		// window.draw(bullet);	
		window.display();
	}

	return 0;
}
//

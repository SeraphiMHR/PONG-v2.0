#pragma once
#include <SFML\Graphics.hpp>
class Ball
{
public:
	Ball();
	~Ball();
	sf::Vector2f pos;
	sf::CircleShape ball;
	sf::Vector2f dir;
	void drawTo(sf::RenderWindow &window);
	void move(float d);   //!
};


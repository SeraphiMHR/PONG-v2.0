#pragma once
#include <SFML\Graphics.hpp>

class Racket
{
public:
	Racket(bool left);
	~Racket();
	sf::Vector2f pos;
	sf::RectangleShape racket;
	void drawTo(sf::RenderWindow &window);
	void move(bool left, float d);
	bool left;
};


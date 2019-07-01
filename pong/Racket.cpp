#include "Racket.h"
#include "GlobalniePer.h"


Racket::Racket(bool left)
{
	racket.setSize({10, 80});
	racket.setFillColor(sf::Color::White);
	racket.setOrigin(0, 40);
	if (left)
	{
		pos = { 10, height / 2 };
	}
	else
	{
		pos = { width - 20, height / 2 };
	}

}

void Racket::drawTo(sf::RenderWindow &window)
{
	racket.setPosition(pos);
	window.draw(racket);
}

void Racket::move(bool left, float d)  //float d
{
	if (left)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			pos.y-= 0.5 * d;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			pos.y+=0.5 * d;
	}
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			pos.y -= 0.5 * d;   // * d
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			pos.y += 0.5 * d;   // * d
	}
	if (pos.y < 50) pos.y = 50;    //if (pos.y <= 50) pos.y++; 
	if (pos.y > 670) pos.y = 670;  //if (pos.y >= 670) pos.y--;
}



Racket::~Racket()
{
}

#include "Ball.h"
#include "GlobalniePer.h"



Ball::Ball()
{
	ball.setRadius(5);
	ball.setFillColor(sf::Color::Yellow);
	pos = { width / 2, height / 2 };
	dir = { 0.3,0.3 };
}
void Ball::drawTo(sf::RenderWindow &window) 
{
	ball.setPosition(pos);
	window.draw(ball);
}

void Ball::move(float d)    //!
{
	pos.x += dir.x * d;     //!   *d
	pos.y += dir.y * d;     //!
	if (pos.y < 10)
	{
		dir.y *= -1;
		pos.y = 10;  //!
	}
	if (pos.y > 700)
	{
		dir.y *= -1;
		pos.y = 700; //!
	}
}


Ball::~Ball()
{
}

#include "Board.h"
#include "GlobalniePer.h"



Board::Board()
{
	board.setSize({ 1280, width/2 });
	board.setFillColor(sf::Color::Green);
	pos = { 0,0 };

}

void Board::drawTo(sf::RenderWindow &window) {
	board.setPosition(pos);
	window.draw(board);
}


Board::~Board()
{
}

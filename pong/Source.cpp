#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Audio/Music.hpp>
#include "GlobalniePer.h"
#include "Racket.h"
#include "Ball.h"

#include <string>
#include <time.h>  //!
#include <Windows.h>  //!
Racket left(1);
Racket right(0);
Ball ball;

float speed = 0;                    //!

void menu(sf::RenderWindow &window) {

	
	sf::Texture Backgr;
	Backgr.loadFromFile("images/back.jpg");
	sf::Sprite backgr(Backgr);
	backgr.setPosition(0, 0);

	sf::Texture Menu1, Menu2, Menu3, About, Pong;
	Menu1.loadFromFile("images/play.png");
	Menu2.loadFromFile("images/about.png");
	Menu3.loadFromFile("images/exit.png");
	About.loadFromFile("images/Programmer.png");
	Pong.loadFromFile("images/Pong.png");

	sf::Sprite menu1(Menu1), menu2(Menu2), menu3(Menu3), about(About), pong(Pong);
	bool isMenu = 1;
	int menunum = 0;
	menu1.setPosition(495, 280);
	menu2.setPosition(495, 360);
	menu3.setPosition(495, 420);
	pong.setPosition(495, 180);
	about.setPosition(0, 0);
	while (isMenu)
	{
		menu1.setColor(sf::Color::White);
		menu2.setColor(sf::Color::White);
		menu3.setColor(sf::Color::White);


		menunum = 0;
		window.clear();
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::IntRect(475, 340, 300, 50).contains(sf::Mouse::getPosition(window))) {
			menu1.setColor(sf::Color::Black); menunum = 1;
		}
		if (sf::IntRect(475, 420, 300, 50).contains(sf::Mouse::getPosition(window))) {
			menu2.setColor(sf::Color::Black); menunum = 2;
		}
		if (sf::IntRect(475, 480, 300, 50).contains(sf::Mouse::getPosition(window))) {
			menu3.setColor(sf::Color::Black); menunum = 3;
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (menunum == 1)	isMenu = false;
			if (menunum == 2) {
				window.draw(backgr);
				window.draw(about);
				window.display();
				while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));
			}
			if (menunum == 3) {
				window.close();
				isMenu = false;
			}
		}
		window.draw(backgr);
		window.draw(pong);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);
		window.display();

	}
}

int Player1_ = 0;
int Player2_ = 0;

void Collision()
{
	if ((ball.pos.y < left.pos.y + 40) && (ball.pos.y > left.pos.y - 40) && (ball.pos.x < 20)) 
	{
		ball.dir.x *= -1;
		ball.pos.x = 20; //!
	}
	if ((ball.pos.y < right.pos.y + 40) && (ball.pos.y > right.pos.y - 40) && (ball.pos.x > 1250)) 
	{
		ball.dir.x *= -1;
		ball.pos.x = 1250;  //!
	}



	if (ball.pos.x < 0)
	{
		ball.pos = { width / 2,height / 2 };
		left.pos = { 10, height / 2 };
		right.pos = { width - 20,height / 2 };
		speed = 0;          //!
		Player1_++;

	}
	if (ball.pos.x > 1265)
	{
		ball.pos = { width / 2,height / 2 };
		left.pos = { 10, height / 2 };
		right.pos = { width - 20,height / 2 };
		speed = 0;          //!
		Player2_++;

	}
}

void main()
{
	sf::Music sound;
	sound.openFromFile("music.ogg");  
	sound.setVolume(10.f);
    sound.play();
	sound.setLoop(true);               


	long long unsigned int tick = 0;    //!
	long long unsigned int frame_period = 0;    //!
	int delta_tick = 0;                 //!
	setlocale(LC_ALL, "Russian");
	sf::RenderWindow window(sf::VideoMode(width, height), "Pong by Student from KFU");
	sf::Texture Backgr;
	Backgr.loadFromFile("images/back1.jpg");
	sf::Sprite backgr(Backgr);
	backgr.setPosition(0, 0);
	back:
	menu(window);
	sf::Text Player1;
	sf::Text Player2;

	sf::Text Name1;
	sf::Text Name2;

	sf::Font Cyrilica;
	Cyrilica.loadFromFile("CyrilicOld.TTF");
	Player1.setFont(Cyrilica);
	Player1.setCharacterSize(30);
	Player1.setFillColor(sf::Color::Color(255, 255, 255));
    Player1.setPosition(width / 2 + 80, 40);

	Player2.setFont(Cyrilica);
	Player2.setCharacterSize(30);
	Player2.setFillColor(sf::Color::Color(255, 255, 255));
	Player2.setPosition(width / 2 - 120, 40);

	Name1.setFont(Cyrilica);
	Name1.setCharacterSize(30);
	Name1.setFillColor(sf::Color::Color(255, 255, 255));
	Name1.setPosition(width / 2 + 50, 0);

	Name2.setFont(Cyrilica);
	Name2.setCharacterSize(30);
	Name2.setFillColor(sf::Color::Color(255,255,255));
	Name2.setPosition(width / 2 - 150, 0);



	while (window.isOpen())
	{

		delta_tick = clock() - tick;
		tick = clock();
		sf::Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))  speed = 1.5;

		Sleep(1);
		Collision();
		left.move(1, delta_tick * speed);

		right.move(0, delta_tick * speed);

		ball.move(delta_tick * speed);
;
		Name1.setString("Игрок 2");

		Name2.setString("Игрок 1");

		Player1.setString(std::to_string(Player1_));

		Player2.setString(std::to_string(Player2_));

		if (clock() - frame_period > 60 / CLOCKS_PER_SEC)   //!
		{
			frame_period = clock();
			window.clear();
			window.draw(backgr);
			
			left.drawTo(window);
			right.drawTo(window);
			ball.drawTo(window);
			window.draw(Name1);
			window.draw(Name2);
			window.draw(Player1);
			window.draw(Player2);
			window.display();
		}
		if (Player1_ == 10 || Player2_ == 10)
		{
			Player1_ = 0;  //!
			Player2_ = 0;  //!
			speed = 0;     //!
			ball.pos = { width / 2,height / 2 };
			left.pos = { 10, height / 2 };
			right.pos = { width - 20,height / 2 };
			goto back;

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
		{
			Player1_ = 0;
			Player2_ = 0;
			speed = 0;     
			ball.pos = { width / 2,height / 2 };
			left.pos = { 10, height / 2 };
			right.pos = { width - 20,height / 2 };
			goto back;

		}
	}
	
}
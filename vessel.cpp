#include <iostream>
#include <cmath>
#include <vector>
#include <SFML/Graphics.hpp>

#include "vessel.hpp"

void Vessel::update()
{
	//Nop
}

Vessel::Vessel()
{
	//Init texture
	this->sprite = new sf::Sprite;
	this->tex = new sf::Texture;

	if(!tex->loadFromFile("./asset/tex/tks_shell.png"))
	{
		std::cout << "ERR: did not load vessel texture\n";
	}
	sprite->setTexture(*tex);
	//Middle of image
	sprite->setOrigin((tex->getSize().x) / 2, (tex->getSize().y) / 2);
	//Middle of screen
	sprite->setPosition(1366/2, 768/2);
	sprite->setRotation(0);
	sprite->setScale(2, 2);

	//Initialize Panles
	panel_sprite = new sf::Sprite;
	computer_tex = new sf::Texture;
	status_tex = new sf::Texture;
	lifesupport_tex = new sf::Texture;

	if(!computer_tex->loadFromFile("./asset/tex/panel/computer.png"))
	{
		std::cout << "ERR: did not load computer panel texture\n";
	}
	if(!status_tex->loadFromFile("./asset/tex/panel/status.png"))
	{
		std::cout << "ERR: did not load status panel texture\n";
	}
	if(!lifesupport_tex->loadFromFile("./asset/tex/panel/life_support.png"))
	{
		std::cout << "ERR: did not load LS panel texture\n";
	}
}

/* void Vessel::draw_panel(Game *game)
{
	switch(game->player.cur_panel)
	{
		case Player::COMPUTER:
			
			break;
		default:
			//uhhh
			game->player.cur_state = Player::FREE;
			game->player.cur_panel = Player::NONE;
			break;
	}
} */

void Vessel::render(sf::RenderWindow *win)
{
	win->draw(*sprite);
}

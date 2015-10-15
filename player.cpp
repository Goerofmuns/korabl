#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

#include "player.hpp"

bool still_pressed = false;

Player::Player()
{
	x_loc = 0;
	y_loc = 20;
	cur_state = FREE;
	cur_panel = NONE;

	//Init texture
	sprite = new sf::Sprite;
	idle_tex = new sf::Texture;
	sit_tex = new sf::Texture;
	move_tex = new sf::Texture;

	//Load textures
	if(!idle_tex->loadFromFile("./asset/tex/natalya/idle.png"))
	{
		std::cout << "ERR: did not load player idle texture\n";
	}
	if(!sit_tex->loadFromFile("./asset/tex/natalya/sit.png"))
	{
		std::cout << "ERR: did not load player sitting texture\n";
	}
	if(!move_tex->loadFromFile("./asset/tex/natalya/move.png"))
	{
		std::cout << "ERR: did not load player moving texture\n";
	}

	sprite->setTexture(*idle_tex);
	//Middle of image
	sprite->setOrigin((idle_tex->getSize().x) / 2, (idle_tex->getSize().y) / 2);
	//Middle of screen plus local position
	sprite->setPosition((1366/2) + x_loc, (768/2) + y_loc);
	sprite->setRotation(0);
	sprite->setScale(2.3, 2.3);
}

void Player::handle_input()
{
	//UPDATE ALL THE THIGSN
	//Left/Right movement
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		x_delta = -0.3;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		x_delta = 0.3;
	}

	//Toggle panel/piloting state
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::E) && still_pressed == false)
	{
		if(cur_state == PILOTING)
		{
			//I'm a pilot get me out of here
			cur_state = FREE;
		}
		else if(x_loc > 30 && cur_state != PILOTING)
		{
			//We wanna get flying
			cur_state = PILOTING;
			cur_panel = FLIGHT;
		}
		else if(x_loc < 30 && x_loc > 400)
		{
			//Read the panel
			cur_state = VIEW_PANEL;
			cur_panel = COMPUTER;
		}
		still_pressed = true;
	}

	//Debouncing
	if(!sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		still_pressed = false;
	}
}

void Player::update(sf::RenderWindow* win)
{
	//Handle it.
	handle_input();

	//Don't go too fast
	if(x_delta > 0.3)
		x_delta = 0.3;
	if(x_delta < -0.3)
		x_delta = -0.3;

	x_loc += x_delta;

	//Don't keep going
	if(x_delta < 0.00)
		x_delta += 0.001;
	if(x_delta > 0.00)
		x_delta -= 0.001;
	if(x_delta < 0.01 && x_delta > -0.01)
		x_delta = 0;

	//Don't fly into space
	if(x_loc < -400)
		x_loc = -400;
	if(x_loc > 35)
		x_loc = 35;


	if(cur_state == PILOTING)
	{
		x_loc = 170;
		y_loc = 10;
	}
}

void Player::render(sf::RenderWindow *win, sf::Clock *clock)
{
	//Set sprite
	if(x_delta != 0)
	{
		if(x_delta < 0)
			sprite->setTextureRect(sf::IntRect(idle_tex->getSize().x, 0, -idle_tex->getSize().x, idle_tex->getSize().y));
		if(x_delta > 0)
			sprite->setTextureRect(sf::IntRect(0, 0, idle_tex->getSize().x, idle_tex->getSize().y));
		sprite->setTexture(*idle_tex);
	}
	if(x_delta == 0)
	{
		sprite->setTexture(*idle_tex);
	}
	if(cur_state == PILOTING)
	{
		sprite->setTexture(*sit_tex);
	}

	//Middle of screen plus local position
	sprite->setPosition((1366/2) + x_loc,
						(768/2) + y_loc + (sin(clock->getElapsedTime().asSeconds())));
	sprite->setRotation(0);
	sprite->setScale(2.3, 2.3);


	win->draw(*sprite);
}

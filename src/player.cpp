#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

#include "player.hpp"

bool still_pressed = false;
bool f_still_pressed = false;

int height;
int width;
sf::Text debug_text;

Player::Player(sf::RenderWindow* app, TextureManager* texmgr)
{
	x_loc = 0;
	y_loc = 20;
	cur_state = FREE;
	cur_panel = NONE;

	height = app->getSize().y;
	width  = app->getSize().x;

	//Init texture
	sprite = new sf::Sprite;
	panel_sprite = new sf::Sprite;
	idle_tex = &texmgr->getRef("idle.png");
	sit_tex = &texmgr->getRef("sit.png");
	move_tex = &texmgr->getRef("move.png");
	panel_tex = &texmgr->getRef("computer_panel.png");

	//Load textures

	sprite->setTexture(*idle_tex);
	//Middle of image
	sprite->setOrigin((idle_tex->getSize().x) / 2, (idle_tex->getSize().y) / 2);
	sprite->setPosition((width/2) + x_loc, (height/2) + y_loc);
	sprite->setRotation(0);
	sprite->setScale(2.3, 2.3);

	panel_sprite->setTexture(*panel_tex);
	panel_sprite->setOrigin((panel_tex->getSize().x) / 2, (panel_tex->getSize().y) / 2);
	panel_sprite->setPosition((width/2), (height/2));
	panel_sprite->setRotation(0);
	panel_sprite->setScale(0.8, 0.8);
}

void Player::handle_input()
{
	//UPDATE ALL THE THINGS
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) && f_still_pressed == false)
	{
		if (cur_state != VIEW_PANEL)
		{
			cur_state = VIEW_PANEL;
			cur_panel = COMPUTER;
		}
		else
		{
			cur_state = FREE;
			cur_panel = NONE;
		}
		f_still_pressed = true;
	}

	//Debouncing
	if(!sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		still_pressed = false;

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::F))
		f_still_pressed = false;
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
        x_delta = 1;
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

	//Middle of screen plus local position
	sprite->setPosition((width/2) + x_loc, (height/2) + y_loc + (sin(clock->getElapsedTime().asSeconds())));
	sprite->setRotation(0);
	sprite->setScale(2.3, 2.3);


	if(x_delta == 0)
	{
		sprite->setTexture(*idle_tex);
	}
	if(cur_state == PILOTING)
	{
		sprite->setTexture(*sit_tex);
	}
	win->draw(*sprite);

	if(cur_state == VIEW_PANEL)
	{
		win->draw(*panel_sprite);
	}
}

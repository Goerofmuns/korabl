#include <iostream>
#include <cmath>
#include <vector>
#include <SFML/Graphics.hpp>

#include "vessel.hpp"
#include "util.hpp"

void Vessel::update()
{
	//Nop
}

void Vessel::render(sf::RenderWindow *win, sf::Clock *clock)
{
	win->draw(*sprite);
}

Vessel::Vessel(sf::RenderWindow* app, TextureManager* texmgr) : GameObject()
{

	int height = app->getSize().y;
	int width  = app->getSize().x;

	//Init texture
	this->sprite = new sf::Sprite;
	this->tex = &texmgr->getRef("tks_shell.png");

	sprite->setTexture(*tex);
	sprite->setOrigin((tex->getSize().x) / 2, (tex->getSize().y) / 2); //Middle of image
	sprite->setPosition(width/2, height/2); //Middle of screen
	sprite->setRotation(0);
	sprite->setScale(GLOBAL_SCALE, GLOBAL_SCALE);
}


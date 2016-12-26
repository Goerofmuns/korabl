#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

#include "player.hpp"
#include "util.hpp"
#include "space_math.hpp"

bool still_pressed = false;

int height;
int width;
sf::Text debug_text;
sf::Font debug_font;

Player::Player(sf::RenderWindow* app, TextureManager* texmgr) : GameObject()
{
    debug_font.loadFromFile("Courier New.ttf");
    debug_text.setFont(debug_font);
    debug_text.setCharacterSize(34);

	loc.X = 0;
	loc.Y = 20;
    delta.X = 0;

	height = app->getSize().y;
	width  = app->getSize().x;

	//Init texture
	this->idle_tex = &texmgr->getRef("idle.png");
	sprite = new sf::Sprite;

	//Load textures
	sprite->setTexture(*idle_tex);
	sprite->setOrigin((idle_tex->getSize().x) / 2, (idle_tex->getSize().y) / 2);
	sprite->setPosition((width/2) + loc.X, (height/2) + loc.Y);
	sprite->setRotation(0);
	sprite->setScale(GLOBAL_SCALE, GLOBAL_SCALE);
}

void Player::handle_input()
{
	//UPDATE ALL THE THINGS
	//Left/Right movement
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		delta.X = -X_SPEED;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		delta.X = X_SPEED;
	}

    //Up/Down movement
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		delta.Y = -Y_SPEED;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		delta.Y = Y_SPEED;
	}

	//Debouncing
	if(!sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		still_pressed = false;
}

//This is gonna get ugly...
void Player::update()
{
	//Handle it.
	handle_input();

    // X STUFF
	//Don't go too fast
	if(delta.X > 0.3)
		delta.X = 0.3;
	if(delta.X < -0.3)
		delta.X = -0.3;

	loc.X += delta.X;

	//Don't keep going
	if(delta.X < 0.00)
		delta.X += 0.001;
	if(delta.X > 0.00)
		delta.X -= 0.001;
	if(delta.X < 0.01 && delta.X > -0.01)
		delta.X = 0;

	//Don't fly into space
	if(loc.X < X_MIN)
		loc.X = X_MIN;
	if(loc.X > X_MAX)
		loc.X = X_MAX;

    // Y STUFF
	//Don't go too fast
	if(delta.Y > 0.3)
		delta.Y = 0.3;
	if(delta.Y < -0.3)
		delta.Y = -0.3;

	loc.Y += delta.Y;

	//Don't keep going
	if(delta.Y < 0.00)
		delta.Y += 0.001;
	if(delta.Y > 0.00)
		delta.Y -= 0.001;
	if(delta.Y < 0.01 && delta.Y > -0.01)
		delta.Y = 0;

	//Don't fly into space
	if(loc.Y < Y_MIN)
		loc.Y = Y_MIN;
	if(loc.Y > Y_MAX)
		loc.Y = Y_MAX;

    debug_text.setString(std::string("[DEBUG]POS:") + std::to_string(loc.X));
}

void Player::render(sf::RenderWindow *win, sf::Clock *clock)
{
	//Middle of screen plus local position
	sprite->setPosition((width/2) + loc.X, (height/2) + loc.Y + (sin(clock->getElapsedTime().asSeconds())));
	sprite->setRotation(delta.X * 20);
	sprite->setScale(2.3, 2.3);

    win->draw(debug_text);

	win->draw(*sprite);
}

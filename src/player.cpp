#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

#include "player.hpp"
#include "util.hpp"
#include "space_math.hpp"

int height;
int width;
sf::Text debug_text;
sf::Font debug_font;

Player::Player(sf::RenderWindow* app, TextureManager* texmgr) : GameObject()
{
    debug_font.loadFromFile("asset/Courier New.ttf");
    debug_text.setFont(debug_font);
    debug_text.setCharacterSize(34);

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
		lin_delta.X = -X_SPEED;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		lin_delta.X = X_SPEED;
	}

    //Up/Down movement
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		lin_delta.Y = -Y_SPEED;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		lin_delta.Y = Y_SPEED;
	}
}

//This is gonna get ugly...
void Player::update()
{
	handle_input();

    // X STUFF
	//Don't go too fast
	if(lin_delta.X > 0.3)
		lin_delta.X = 0.3;
	if(lin_delta.X < -0.3)
		lin_delta.X = -0.3;

	loc.X += lin_delta.X;

	//Don't keep going
	if(lin_delta.X < 0.00)
		lin_delta.X += 0.001;
	if(lin_delta.X > 0.00)
		lin_delta.X -= 0.001;
	if(lin_delta.X < 0.01 && lin_delta.X > -0.01)
		lin_delta.X = 0;

    // Y STUFF
	//Don't go too fast
	if(lin_delta.Y > 0.3)
		lin_delta.Y = 0.3;
	if(lin_delta.Y < -0.3)
		lin_delta.Y = -0.3;

	loc.Y += lin_delta.Y;

	//Don't keep going
	if(lin_delta.Y < 0.00)
		lin_delta.Y += 0.001;
	if(lin_delta.Y > 0.00)
		lin_delta.Y -= 0.001;
	if(lin_delta.Y < 0.01 && lin_delta.Y > -0.01)
		lin_delta.Y = 0;


    debug_text.setString(
		std::string("POS:") + loc.to_string() +
				  "\nDEL:"  + lin_delta.to_string());
}

void Player::render(sf::RenderWindow *win, sf::Clock *clock)
{
    win->draw(debug_text);

	//Middle of screen plus local position
	sprite->setPosition((width/2) + loc.X, (height/2) + loc.Y);

	win->draw(*sprite);
}

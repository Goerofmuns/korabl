#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "vessel.hpp"

void Vessel::update()
{
	rot+=rot_delta;
	sf::Vector2f dir = sf::Vector2f(cos(rot * 3.141592/180), sin(rot * 3.141592/180));
	y_delta+=s_delta * dir.y;
	x_delta+=s_delta * dir.x;
	x_loc += x_delta;
	y_loc += y_delta;

	s_delta = 0;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		translateJet(-0.1);
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		translateJet(0.1);
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		rotateJet(-0.1);
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		rotateJet(0.1);
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		rot_delta = 0;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		y_delta = 0;
		x_delta = 0;
	}
}

Vessel::Vessel()
{
	x_loc = 300;
	y_loc = 300;
	x_delta = 0;
	y_delta = 0;
	s_delta = 0;
	rot = 0;
	rot_delta = 0;
}

void Vessel::translateJet(float val)
{
	if(val > 1.0f)
		val = 1.0f;
	if(val < -1.0f)
		val = -1.0f;

	s_delta = val;
}

void Vessel::rotateJet(float val)
{
	if(val > 1.0f)
		val = 1.0f;
	if(val < -1.0f)
		val = -1.0f;

	rot_delta += val;
}

sf::Sprite Vessel::renderVessel()
{
	sf::Sprite ret;
	sf::Texture *tex = new sf::Texture;

	if(!tex->loadFromFile("./asset/tex/vessel.png"))
	{
		std::cout << "ERR: did not load vessel texture\n";
	}
	ret.setTexture(*tex);
	ret.setPosition(sf::Vector2f(x_loc, y_loc));
	ret.setRotation(rot - 90);
	ret.setOrigin(sf::Vector2f(32, 32));

	return ret;
}

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

#include "player.hpp"
#include "util.hpp"
#include "space_math.hpp"

bool still_pressed = false;
bool f_still_pressed = false;
bool r_still_pressed = false;

int height;
int width;
sf::Text debug_text;

Player::Player(sf::RenderWindow* app, TextureManager* texmgr) : GameObject()
{
	loc->X = 0;
	loc->Y = 20;
    delta->X = 0;

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
	sprite->setOrigin((idle_tex->getSize().x) / 2, (idle_tex->getSize().y) / 2);
	sprite->setPosition((width/2) + loc->X, (height/2) + loc->Y);
	sprite->setRotation(0);
	sprite->setScale(GLOBAL_SCALE, GLOBAL_SCALE);

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
		delta->X = -X_SPEED;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		delta->X = X_SPEED;
	}

    //Up/Down movement
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		delta->Y = -Y_SPEED;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		delta->Y = Y_SPEED;
	}


	//Toggle panel/piloting state
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::E) && still_pressed == false)
	{
		if(cur_state == PILOTING || cur_state == VIEW_PANEL)
		{
			//stop piloting or looking at panel
			cur_state = FREE;
		}
		else if(loc->X > 30 && cur_state != PILOTING)
		{
			//We wanna get flying
			cur_state = PILOTING;
			cur_panel = FLIGHT;
		}
		else if(loc->X < 30 && loc->X > 400)
		{
			//Read the panel
			cur_state = VIEW_PANEL;
			cur_panel = COMPUTER;
		}
    else if(loc->X < -10 && loc->X > -30)
    {
      if(cur_state != VIEW_PANEL)
        {
          cur_state = VIEW_PANEL;
          cur_panel = COMPUTER;
        }
      else if(cur_state == VIEW_PANEL)
        {
          cur_state = FREE;
        }
    }
		still_pressed = true;
	}

  //Print Debug text
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && r_still_pressed == false)
    {
      std::cout << "--DEBUG--" << "\n";
      std::cout << "POS: " << loc->X << ":" << loc->Y << "\n";
      std::cout << "--DEBUG--" << "\n";
    }

	//Debouncing
	if(!sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		still_pressed = false;

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::F))
		f_still_pressed = false;

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		r_still_pressed = false;
}

//This is gonna get ugly...
virtual void Player::update(sf::RenderWindow* win)
{
	//Handle it.
	handle_input();

    // X STUFF
	//Don't go too fast
	if(delta->X > 0.3)
		delta->X = 0.3;
	if(delta->X < -0.3)
		delta->X = -0.3;

	loc->X += delta->X;

	//Don't keep going
	if(delta->X < 0.00)
		delta->X += 0.001;
	if(delta->X > 0.00)
		delta->X -= 0.001;
	if(delta->X < 0.01 && delta->X > -0.01)
		delta->X = 0;

	//Don't fly into space
	if(loc->X < X_MIN)
		loc->X = X_MIN;
	if(loc->X > X_MAX)
		loc->X = X_MAX;

    // Y STUFF
	//Don't go too fast
	if(delta->Y > 0.3)
		delta->Y = 0.3;
	if(delta->Y < -0.3)
		delta->Y = -0.3;

	loc->Y += delta->Y;

	//Don't keep going
	if(delta->Y < 0.00)
		delta->Y += 0.001;
	if(delta->Y > 0.00)
		delta->Y -= 0.001;
	if(delta->Y < 0.01 && delta->Y > -0.01)
		delta->Y = 0;

	//Don't fly into space
	if(loc->Y < Y_MIN)
		loc->Y = Y_MIN;
	if(loc->Y > Y_MAX)
		loc->Y = Y_MAX;

	if(cur_state == PILOTING)
	{
		loc->X = 170;
        loc->Y = 10;
        delta->X = 1;
	}
}

virtual void Player::render(sf::RenderWindow *win, sf::Clock *clock)
{
	//Set sprite
	if(delta->X != 0)
	{
		if(delta->X < 0)
			sprite->setTextureRect(sf::IntRect(idle_tex->getSize().x, 0, -idle_tex->getSize().x, idle_tex->getSize().y));
		if(delta->X > 0)
			sprite->setTextureRect(sf::IntRect(0, 0, idle_tex->getSize().x, idle_tex->getSize().y));

		sprite->setTexture(*idle_tex);
	}

	//Middle of screen plus local position
	sprite->setPosition((width/2) + loc->X, (height/2) + loc->Y + (sin(clock->getElapsedTime().asSeconds())));
	sprite->setRotation(delta->X * 20);
	sprite->setScale(2.3, 2.3);


	if(delta->X == 0)
	{
		sprite->setTexture(*idle_tex);
	}

    // we are crawling through tunnel
    if(loc->X > 50 && loc->X < 100)
    {
        sprite->setRotation(math::norm(delta->X) * 80);
    }

	if(cur_state == PILOTING)
	{
		sprite->setTexture(*sit_tex);
        sprite->setRotation(0);
	}

	win->draw(*sprite);

	if(cur_state == VIEW_PANEL)
	{
		win->draw(*panel_sprite);
	}
}

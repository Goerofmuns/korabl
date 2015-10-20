#include <iostream>

#include "game.hpp"

void Game::loop()
{
	while(app.isOpen())
	{
		sf::Event event;
		while(app.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				app.close();
			}

			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				app.close();
			}
			if(sf::Event::Resized)
			{
				view.setSize(app.getSize().x, app.getSize().y);
				app.setView(view);
			}
		}

		//Update player
                player.update(&app);

		//Look at panels
		/*if(player.cur_state == Player::VIEW_PANEL)
		{
			cpanel.update(&player);
			cpanel.render(&app);
                }*/

		app.clear();
		
		//They can draw themselves
		vessel.render(&app);
		player.render(&app, &clock);

		//Et voila
		app.display();
	}
}

Game::Game() : texmgr(), player(&texmgr),  vessel(&texmgr), app(sf::VideoMode(200, 200), "SPOICE", sf::Style::Fullscreen)
{
	this->view = app.getView(); //This is for resize thignys
}

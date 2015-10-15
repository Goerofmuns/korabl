#include <iostream>

#include "game.hpp"
#include "tinydir.h"

void walk_tex_dir(Game *game, const char* dirname)
{
	tinydir_dir dir;
	tinydir_open(&dir, dirname);
	while(dir.has_next)
	{
		tinydir_file file;
		tinydir_readfile(&dir, &file);

		if(file.is_dir)
		{
			walk_tex_dir(game, file.path);
		}
		else
		{
			game->texmgr.loadTexture(file.name, file.path);
		}
	}
}

void Game::load_textures()
{
	std::cout << "Loading Textures...\n";
	walk_tex_dir(this, "./asset/tex/");
}

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
		if(player.cur_state == Player::VIEW_PANEL)
		{
			cpanel.update(&player);
			cpanel.render(&app);
		}

		app.clear();
		
		//They can draw themselves
		vessel.render(this);
		player.render(this, &clock);

		//Et voila
		app.display();
	}
}

Game::Game()
{
	sf::RenderWindow app(sf::VideoMode(200, 200), "SPOICE", sf::Style::Fullscreen); //Construct window
	view = app.getView(); //This is for resize thignys
	load_textures(); //Load the textures

	//Ready to roll
}

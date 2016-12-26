#include <iostream>
#include <string>

using std::string;

#include "game.hpp"
#include "module.hpp"

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

		//Update gameobjects
        for (auto* obj : objectVector)
        {
            obj->update();
        }

		app.clear();

		//They can draw themselves
        for (auto* obj : objectVector)
        {
            obj->render(&app, &clock);
        }

		//Et voila
		app.display();
	}
}

Game::Game() : app(sf::VideoMode(1680, 1050), "korabl", sf::Style::Fullscreen), texmgr()
{
	this->view = app.getView(); //This is for resize thignys

    //add gameobjects
    this->objectVector.push_back(new Player(&app, &texmgr));
    this->objectVector.push_back(new Vessel(&app, &texmgr));
	this->objectVector.push_back(new Module(string("TKS"), string("space caravan"), {4, 10}, 45, {{"a", {4, 10}}}, {{"b", {0, 2}}}, &texmgr))
}

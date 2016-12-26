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

Game::Game() : app(sf::VideoMode(1680, 1050), "korabl", sf::Style::Resize), texmgr()
{
	this->view = app.getView(); //This is for resize thignys

    //add gameobjects
	int arr[2] = {4, 10};
	this->objectVector.push_back(new Module(string("TKS"), string("space caravan"), arr, 45, &app, &texmgr));

//    this->objectVector.push_back(new Vessel());
    this->objectVector.push_back(new Player(&app, &texmgr));

}

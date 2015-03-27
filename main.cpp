#include <SFML/Graphics.hpp>
#include <iostream>

#include "vessel.hpp"

int main()
{
	Vessel vessel;

	//Rendering things
	sf::RenderWindow window(sf::VideoMode(200, 200), "SPOICE");
	sf::Texture *tex = new sf::Texture;
	sf::Texture tab_texture;
	sf::Sprite tab;

	tab_texture.loadFromFile("asset/tex/tab_computer.png");
	tab.setTexture(tab_texture);
	tab.setOrigin(64, 32);
	tab.setPosition(1366, 728);

	while(window.isOpen())
	{

		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		//Update thigns
		vessel.update();

		//Render things
		sf::Sprite vesselSprite = vessel.renderVessel();

		//Draw things
		window.clear();
		window.draw(vesselSprite);
		window.draw(tab);
		window.display();
	}

	return 0;
}

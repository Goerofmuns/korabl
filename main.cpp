#include <SFML/Graphics.hpp>
#include <iostream>

#include "vessel.hpp"
#include "cScreen.hpp"
#include "screen_space.hpp"

int main()
{
	//std::vector<cScreen*> vScreens;
	int cur_screen = 0;

	ScreenSpace sc_space;
	//vScreens.push_back(&sc_space);

	//Rendering things
	sf::RenderWindow window(sf::VideoMode(200, 200), "SPOICE");

	while(window.isOpen())
	{
		//vScreens[0]->update(window);
		sc_space.update(window);
	}

	return 0;
}

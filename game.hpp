#ifndef __GAME_H__
#define __GAME_H__

#include <SFML/Graphics.hpp>

#include "player.hpp"
#include "vessel.hpp"
//#include "computer_panel.hpp"
#include "texture_manager.hpp"

class Game
{
public:
	sf::RenderWindow app;
	sf::View view;
	sf::Clock clock;
	TextureManager texmgr;


	Player player;
	Vessel vessel;
        //	ComputerPanel cpanel;

	Game();
	void loop();

private:
	void load_textures();
};

#endif

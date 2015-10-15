#ifndef __COMPUTER_PANEL_H__
#define __COMPUTER_PANEL_H__

#include<SFML/Graphics.hpp>
#include "game.hpp"

class ComputerPanel
{
public:

	ComputerPanel();
	void update(Game*);
	void render(sf::RenderWindow*);

private:
	int addr_value;
	sf::FloatRect addr_panel_rect;

	sf::Sprite back_panel_sprite;
	sf::Sprite addr_panel_sprite;
};

#endif

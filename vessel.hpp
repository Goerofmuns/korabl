#ifndef __VESSEL_H__
#define __VESSEL_H__

#include <SFML/Graphics.hpp>

#include "texture_manager.hpp"

//The class that holds vessel info, does handle physics or wotnot
class Vessel
{
public:
	Vessel(TextureManager*);

	//void draw_panel(sf::RenderWindow);
	void update();
	void render(sf::RenderWindow*);

private:
	int air_pressure = 1;

	sf::Sprite *sprite;
	sf::Texture *tex;

	sf::Sprite *panel_sprite;
	sf::Texture *computer_tex;
	sf::Texture *status_tex;
	sf::Texture *lifesupport_tex;

};

#endif

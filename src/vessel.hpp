#ifndef __VESSEL_H__
#define __VESSEL_H__

#include <SFML/Graphics.hpp>

#include "texture_manager.hpp"

//The class that holds vessel info and data
class Vessel
{
public:
	Vessel(sf::RenderWindow*, TextureManager*);

	//void draw_panel(sf::RenderWindow);
	void update();
	void render(sf::RenderWindow*);

    // state
    bool hatch_open = false; //Is the hatch open?
    float atm_pres = 1;      //what is the pressure?

private:

	sf::Sprite *sprite;
	sf::Texture *tex;

	sf::Sprite *panel_sprite;
	sf::Texture *computer_tex;
	sf::Texture *status_tex;
	sf::Texture *lifesupport_tex;

};

#endif

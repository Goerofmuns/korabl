#ifndef __VESSEL_H__
#define __VESSEL_H__

#include <SFML/Graphics.hpp>

#include "texture_manager.hpp"
#include "util.hpp"

//The class that holds vessel info and data
class Vessel : public GameObject
{
public:
	Vessel(sf::RenderWindow*, TextureManager*);

	//void draw_panel(sf::RenderWindow);
    virtual void update();
	virtual void render(sf::RenderWindow*, sf::Clock*);

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

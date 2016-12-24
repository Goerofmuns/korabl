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

    //individual properties
    std::string shipName;
    float pressure;

private:

	sf::Sprite *sprite;
	sf::Texture *tex;

};

#endif

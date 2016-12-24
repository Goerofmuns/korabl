#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <SFML/Graphics.hpp>

#include "texture_manager.hpp"
#include "util.hpp"

class Player : public GameObject
{
public:
	Player(sf::RenderWindow*, TextureManager*);
	sf::Sprite *sprite;
	sf::Texture *idle_tex;

	virtual void update();
	virtual void render(sf::RenderWindow*, sf::Clock*);

private:
	void handle_input();
};

#endif

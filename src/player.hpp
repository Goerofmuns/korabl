#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <SFML/Graphics.hpp>

#include "texture_manager.hpp"

class Player
{
public:

	enum player_state
	{
		PILOTING,
		VIEW_PANEL,
		FREE
	};

	enum viewing_panel
	{
		NONE,
		FLIGHT,
		LIFE_SUPPORT,
		STATUS,
		COMPUTER
	};

	Player(sf::RenderWindow*, TextureManager*);
//	~Player();
	//X and Y locations and deltas
	//float x_loc, y_loc;
	//float x_delta, y_delta;
	//Rotation in degrees
	//float rot;

	player_state cur_state;
	viewing_panel cur_panel;

	sf::Sprite *sprite;
	sf::Sprite *panel_sprite;
	sf::Texture *idle_tex;
	sf::Texture *sit_tex;
	sf::Texture *move_tex;
	sf::Texture *panel_tex;

	virtual void update(sf::RenderWindow*);
	virtual void render(sf::RenderWindow*, sf::Clock*);

private:
	void handle_input();
};

#endif

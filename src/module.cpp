#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "module.hpp"
#include "util.hpp"

void Module::update()
{

}

void Module::render(sf::RenderWindow *win, sf::Clock *clock)
{
    win->draw(*sprite);
}

Module::Module(string _name, string _description, std::pair<int, int> _size, int _volume, sf::RenderWindow *app, TextureManager *texman) : GameObject()
{
    this->name = _name;
    this->description = _description;
    this->size = _size;
    this->volume = _volume;
//    this->sections = _sections;
//    this->docking_nodes = _docking_nodes;

    this->sprite = new sf::Sprite;
    this->tex = &texman->getRef("int_texture.png");

	int height = app->getSize().y;
	int width  = app->getSize().x;

    sprite->setTexture(*tex);
	sprite->setOrigin((tex->getSize().x) / 2, (tex->getSize().y) / 2); //Middle of image
	sprite->setPosition(width/2, height/2); //Middle of screen
	sprite->setRotation(0);
	sprite->setScale(GLOBAL_SCALE, GLOBAL_SCALE);
};

#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <map>

#include "texture_manager.hpp"
#include "util.hpp"

using std::string;
using std::map;

class Module : public GameObject
{
public:
    string name;
    string description;
    std::pair<int, int> size;
    int volume;

    map<string, int[2]> sections;
    map<string, int[2]> docking_nodes;

    virtual void update();
    virtual void render(sf::RenderWindow*, sf::Clock*);
    Module(string _name, string _description, std::pair<int, int> _size, int _volume, sf::RenderWindow*, TextureManager*);

private:
    sf::Sprite *sprite;
    sf::Texture *tex;
};

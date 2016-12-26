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
    int size[2] = {4, 10};
    int volume;

    map<string, int[2]> sections;
    map<string, int[2]> docking_nodes;

    virtual void update();
    virtual void render(sf::RenderWindow*, sf::Clock*);
    Module(string _name, string _description, int _size[2], int _volume, map<string, int[2]> _sections, map<string, int[2]> _docking_nodes, TextureManager*);

private:
    sf::Sprite *sprite;
    sf::Texture *tex;
};

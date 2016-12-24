#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <string>

#include "texture_manager.hpp"

void TextureManager::loadTexture(const std::string& name, const std::string& filename)
{
	sf::Texture tex;
	tex.loadFromFile(filename);

	textures[name] = tex;

	return;
}

sf::Texture& TextureManager::getRef(const std::string& name)
{
	return textures.at(name);
}

TextureManager::TextureManager()
{
    loadTexture("tks_shell.png", "./asset/tex/tks_shell.png");
    loadTexture("idle.png", "./asset/tex/natalya/idle.png");
    loadTexture("sit.png", "./asset/tex/natalya/sit.png");
    loadTexture("move.png", "./asset/tex/natalya/move.png");
    loadTexture("computer_panel.png", "./asset/tex/computer_panel.png");
}

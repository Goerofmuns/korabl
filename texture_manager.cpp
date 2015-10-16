#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <string>

#include "texture_manager.hpp"
#include "tinydir.h"

void walk_tex_dir(TextureManager *texmgr, const char* dirname)
{
	tinydir_dir dir;
	tinydir_open(&dir, dirname);
	while(dir.has_next)
	{
		tinydir_file file;
		tinydir_readfile(&dir, &file);

		if(file.is_dir)
		{
			walk_tex_dir(texmgr, file.path);
		}
		else
		{
			texmgr->loadTexture(file.name, file.path);
		}
	}
}

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
        std::cout << "Loading Textures...\n";
        //walk_tex_dir(this, "asset/tex");
        loadTexture("tks_shell.png", "./asset/tex/tks_shell.png");
}

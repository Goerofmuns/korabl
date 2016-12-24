#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <string>

#include "texture_manager.hpp"

/*void add_tex_dir(TextureManager* texmgr, const char* dirname)
{
        DIR *dpdf;
        struct dirent *epdf;

        dpdf = opendir("./asset/tex/");
        while((epdf = readdir(dpdf)))
        {
                if(epdf != NULL)
                {
                        if(strstr(epdf->d_name, ".png"))
                                std::cout << epdf->d_type;
                                texmgr->loadTexture(epdf->d_name, strcat("./asset/tex/", epdf->d_name));
                }
        }
}*/

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
        loadTexture("tks_shell.png", "./asset/tex/tks_shell.png");
        loadTexture("idle.png", "./asset/tex/natalya/idle.png");
        loadTexture("sit.png", "./asset/tex/natalya/sit.png");
        loadTexture("move.png", "./asset/tex/natalya/move.png");
        loadTexture("computer_panel.png", "./asset/tex/computer_panel.png");
}

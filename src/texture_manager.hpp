#ifndef __TEXTURE_MANAGER_H__
#define __TEXTURE_MANAGER_H__

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class TextureManager
{
public:
	void loadTexture(const std::string &name, const std::string &filename);
	sf::Texture& getRef(const std::string& texture);
	TextureManager();

private:
	std::map<std::string, sf::Texture> textures;
};

#endif

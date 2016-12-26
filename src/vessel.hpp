#ifndef __VESSEL_H__
#define __VESSEL_H__

#include <SFML/Graphics.hpp>

#include "texture_manager.hpp"
#include "module.hpp"
#include "util.hpp"

//The class that holds vessel info and data
class Vessel
{
public:
	Vessel();

private:
	std::vector<Module> modules;
};

#endif

#include <iostream>

#include "module.hpp"

// Parses JSON files into Module classes
class ModuleParser
{
public:
    static Module* createModuleFromJSON(std::string);
};
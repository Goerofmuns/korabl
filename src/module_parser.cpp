#include <iostream>

#include "module_parser.hpp"
#include "module.hpp"
#include "json.hpp"

using json = nlohmann::json;

Module* ModuleParser::createModuleFromJSON(std::string jsonString)
{
    json module_j = json::parse(jsonString);
    std::cout << std::setw(4) << module_j;

    auto thing = module_j.at(3);
    std::pair<int, int> arr = std::pair<int, int> {4, 10};
    return new Module(module_j.at(0), //name
                      module_j.at(1), //description
                      arr,            //size array
                      module_j.at(3), //volume
                      NULL,           //renderwindow
                      NULL);          //texture manager
}
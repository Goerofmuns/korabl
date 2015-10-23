#include <SFML/Graphics.hpp>

#include "computer_panel.hpp"

ComputerPanel::ComputerPanel()
{
	//Construct it
	addr_value = 01234567; //address readout value
	
	addr_panel_rect = sf::FloatRect(500, 500, 200, 200);
}

void ComputerPanel::update()
{
	
}

void ComputerPanel::render(sf::RenderWindow* app)
{
	
}

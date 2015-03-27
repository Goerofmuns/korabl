#ifndef __SCREEN_SPACE_H__
#define __SCREEN_SPACE_H__

class ScreenSpace : public cScreen
{
	public:
		virtual int update(sf::RenderWindow &window);	
		ScreenSpace();

	private:
		Vessel vessel;
		sf::Texture *tex = new sf::Texture;
		sf::Texture tab_texture;
		sf::Sprite tab;
};

ScreenSpace::ScreenSpace()
{
	tab_texture.loadFromFile("asset/tex/tab_computer.png");
	tab.setTexture(tab_texture);
	tab.setOrigin(64, 32);
	tab.setPosition(1366, 728);
}

int ScreenSpace::update(sf::RenderWindow &window)
{
	sf::Event event;
	while(window.pollEvent(event))
	{
		if(event.type == sf::Event::Closed)
		{
			window.close();
		}
	}

	//Update thigns
	vessel.update();

	//Render things
	sf::Sprite vesselSprite = vessel.renderVessel();

	//Draw things
	window.clear();
	window.draw(vesselSprite);
	window.draw(tab);
	window.display();

	return 1;
}

#endif

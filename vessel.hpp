#ifndef __VESSEL_H__
#define __VESSEL_H__

#include <SFML/Graphics.hpp>

//The class that holds vessel info, does handle physics or wotnot
class Vessel
{
	public:
		//X and Y coordinates
		float x_loc, y_loc;
		float x_delta, y_delta, s_delta;
		//Rotation in degrees.
		float rot;
		float rot_delta;

		void rotateJet(float);
		void translateJet(float);

		void update();
		Vessel();
		sf::Sprite renderVessel();

};

#endif

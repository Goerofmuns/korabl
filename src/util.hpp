#ifndef __UTIL_H__
#define __UTIL_H__

#include <SFML/System.hpp>
#include "space_math.hpp"

const float GLOBAL_SCALE = 2;

//Player things
const float X_SPEED = 0.3;
const float X_MIN   = -400;
const float X_MAX   = 140;
const float Y_SPEED = 0.3;
const float Y_MAX = 20;
const float Y_MIN = -20;

using namespace Math::Vector;

class GameObject
{
public:
    Vector2 loc;
    Vector2 delta;

    virtual void update(sf::RenderWindow);
    virtual void render(sf::RenderWindow*, sf::Clock*);
    GameObject()
    {
        this->loc = Vector2(0.0, 0.0);
        this->delta = Vector2(0.0, 0.0);
    }
};

#endif

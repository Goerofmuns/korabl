#ifndef __UTIL_H__
#define __UTIL_H__

#include <SFML/System.hpp>

#include "space_math.hpp"

const float GLOBAL_SCALE = 1;

//Player things
const float X_SPEED = 0.3;
const float Y_SPEED = 0.3;

class GameObject
{
public:
    Math::Vector2 loc;
    Math::Vector2 lin_delta;
    float rot;
    float rot_delta;

    virtual void update() = 0;
    virtual void render(sf::RenderWindow*, sf::Clock*) = 0;
    inline GameObject()
    {
        this->loc = Math::Vector2(0.0, 0.0);
        this->lin_delta = Math::Vector2(0.0, 0.0);
    }
};

#endif

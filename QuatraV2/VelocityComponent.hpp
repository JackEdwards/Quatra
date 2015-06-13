#ifndef VELOCITYCOMPONENT_HPP
#define VELOCITYCOMPONENT_HPP

#include "Component.hpp"

class VelocityComponent : public Component
{
public:
    sf::Vector2f _velocity;
    float _acceleration;

public:
    VelocityComponent(float x, float y, float acceleration);
};

#endif

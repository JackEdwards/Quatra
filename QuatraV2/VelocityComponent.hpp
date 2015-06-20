#ifndef VELOCITYCOMPONENT_HPP
#define VELOCITYCOMPONENT_HPP

#include "Component.hpp"

class VelocityComponent : public Component
{
public:
    sf::Vector2f m_velocity;
    float m_speed;

public:
    VelocityComponent(sf::Vector2f velocity, float speed);
};

typedef std::shared_ptr<VelocityComponent> VelocityComponentPtr;

#endif

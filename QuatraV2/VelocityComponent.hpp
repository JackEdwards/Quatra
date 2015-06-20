#ifndef VELOCITYCOMPONENT_HPP
#define VELOCITYCOMPONENT_HPP

#include "Component.hpp"

class VelocityComponent : public Component
{
public:
    ComponentType m_type;
    sf::Vector2f m_velocity;
    float m_speed;

public:
    VelocityComponent();
    void Init(sf::Vector2f velocity, float speed);
};

typedef std::shared_ptr<VelocityComponent> VelocityComponentPtr;

#endif

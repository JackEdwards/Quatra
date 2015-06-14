#include "VelocityComponent.hpp"

VelocityComponent::VelocityComponent(sf::Vector2f velocity, float acceleration)
{
    _type = ComponentType::Velocity;

    _velocity = velocity;
    _acceleration = acceleration;
}
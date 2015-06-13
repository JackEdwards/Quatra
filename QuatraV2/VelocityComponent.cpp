#include "VelocityComponent.hpp"

VelocityComponent::VelocityComponent(float x, float y, float acceleration)
{
    _flag = ComponentFlag::Velocity;

    _velocity = sf::Vector2f(x, y);
    _acceleration = acceleration;
}
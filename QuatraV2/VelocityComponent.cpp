#include "VelocityComponent.hpp"

VelocityComponent::VelocityComponent(sf::Vector2f velocity, float acceleration)
{
    m_type = ComponentType::Velocity;

    m_velocity = velocity;
    m_acceleration = acceleration;
}
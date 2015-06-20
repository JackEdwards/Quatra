#include "VelocityComponent.hpp"

VelocityComponent::VelocityComponent(sf::Vector2f velocity, float speed)
{
    m_type = ComponentType::Velocity;

    m_velocity = velocity;
    m_speed = speed;
}
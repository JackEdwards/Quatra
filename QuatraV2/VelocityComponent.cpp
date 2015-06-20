#include "VelocityComponent.hpp"

VelocityComponent::VelocityComponent()
{
    m_type = ComponentType::Velocity;
}

void VelocityComponent::Init(sf::Vector2f velocity, float speed)
{
    m_velocity = velocity;
    m_speed = speed;
}
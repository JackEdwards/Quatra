#include "HealthComponent.hpp"

HealthComponent::HealthComponent()
{
    m_type = ComponentType::Health;
}

void HealthComponent::Init(int health)
{
    m_health = health;
}
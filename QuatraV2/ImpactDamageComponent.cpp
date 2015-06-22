#include "ImpactDamageComponent.hpp"

ImpactDamageComponent::ImpactDamageComponent()
{
    m_type = ComponentType::ImpactDamage;
}

void ImpactDamageComponent::Init(int damage)
{
    m_damage = damage;
}
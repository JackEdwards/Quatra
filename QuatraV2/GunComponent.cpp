#include "GunComponent.hpp"

GunComponent::GunComponent()
{
    m_type = ComponentType::Gun;
}

void GunComponent::Init(float reloadLimit)
{
    m_reloadLimit = reloadLimit;
}
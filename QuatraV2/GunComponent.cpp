#include "GunComponent.hpp"

GunComponent::GunComponent(float reloadLimit)
{
    m_type = ComponentType::Gun;
    
    m_reloadLimit = reloadLimit;
}
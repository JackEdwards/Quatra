#include "PerishableComponent.hpp"

PerishableComponent::PerishableComponent()
{
    m_type = ComponentType::Perishable;
    
    m_shouldPerish = false;
}
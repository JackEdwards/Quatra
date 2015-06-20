#include "PerishableComponent.hpp"

PerishableComponent::PerishableComponent(PerishCondition perishCondition)
{
    m_type = ComponentType::Perishable;
    
    m_perishCondition = perishCondition;
}
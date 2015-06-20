#include "PerishableComponent.hpp"

PerishableComponent::PerishableComponent()
{
    m_type = ComponentType::Perishable;
}

void PerishableComponent::Init(PerishCondition perishCondition)
{
    m_perishCondition = perishCondition;
}
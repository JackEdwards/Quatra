#include "Entity.hpp"

bool Entity::HasComponent(ComponentType type)
{
    if (m_components.count(type) > 0) {
        return true;
    }
    
    return false;
}

void Entity::AddComponent(ComponentPtr component)
{
    m_components.insert(std::pair<ComponentType, ComponentPtr>(component->m_type, component));
    m_types |= component->m_type;
}

void Entity::RemoveComponent(ComponentType type)
{
    if (HasComponent(type)) {
        m_components.erase(type);
        m_types ^= type;
    }
}

ComponentPtr Entity::GetComponent(ComponentType type)
{
    if (HasComponent(type)) {
        return m_components[type];
    }
}


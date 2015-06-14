#include "Entity.hpp"

bool Entity::HasComponent(ComponentType type)
{
    if (_components.count(type) > 0) {
        return true;
    }
    
    return false;
}

void Entity::AddComponent(ComponentPtr component)
{
    _components.insert(std::pair<ComponentType, ComponentPtr>(component->_type, component));
    _types |= component->_type;
}

void Entity::RemoveComponent(ComponentType type)
{
    if (HasComponent(type)) {
        _components.erase(type);
        _types ^= type;
    }
}

ComponentPtr Entity::GetComponent(ComponentType type)
{
    if (HasComponent(type)) {
        return _components[type];
    }
}


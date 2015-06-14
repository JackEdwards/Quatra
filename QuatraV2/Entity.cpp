#include "Entity.hpp"

void Entity::AddComponent(Component* component)
{
    _components.insert(std::pair<ComponentType, Component*>(component->_type, component));
    _types |= component->_type;
}

Component* Entity::GetComponent(ComponentType component)
{
    if (_components.count(component) != 0) {
        return _components[component];
    }
}
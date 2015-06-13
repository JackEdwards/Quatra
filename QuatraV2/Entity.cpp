#include "Entity.hpp"

void Entity::AddComponent(Component* component)
{
    _components.insert(std::pair<ComponentFlag, Component*>(component->_flag, component));
    _flags = _flags | component->_flag;
}
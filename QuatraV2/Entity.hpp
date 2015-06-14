#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <map>
#include "Component.hpp"

class Entity
{
public:
    std::map<ComponentType, Component*> _components;
    long _types;

public:
    virtual ~Entity() = 0;
    void AddComponent(Component* component);
    Component* GetComponent(ComponentType component);
};

inline Entity::~Entity() {};

#endif

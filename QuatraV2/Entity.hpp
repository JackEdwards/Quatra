#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <map>
#include "Component.hpp"

class Entity
{
public:
    std::map<ComponentFlag, Component*> _components;
    long _flags;

public:
    virtual ~Entity() = 0;
    void AddComponent(Component* component);
};

inline Entity::~Entity() {};

#endif

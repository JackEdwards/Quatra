#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <map>
#include "Component.hpp"

class Entity
{
public:
    std::map<ComponentType, ComponentPtr> m_components;
    //long m_types;
    std::bitset<16> m_types;

public:
    virtual ~Entity() = 0;
    bool HasComponent(ComponentType type);
    void AddComponent(ComponentPtr component);
    void RemoveComponent(ComponentType type);
    ComponentPtr GetComponent(ComponentType type);
};

inline Entity::~Entity() {};

typedef std::unique_ptr<Entity> EntityPtr;
typedef std::vector<std::unique_ptr<Entity>> EntityPtrList;

#endif

#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <map>
#include <typeindex>
#include <type_traits>
#include "Component.hpp"

class Entity
{
public:
    std::map<std::type_index, ComponentPtr> m_components;
    std::bitset<16> m_types;

public:
    virtual ~Entity() = 0;
    template <class T> bool HasComponent();
    template <class T> void AddComponent();
    template <class T> void RemoveComponent();
    template <class T> std::shared_ptr<T> GetComponent();
};

inline Entity::~Entity() {};

#include "Entity.tpp"

typedef std::unique_ptr<Entity> EntityPtr;
typedef std::vector<std::unique_ptr<Entity>> EntityPtrList;

#endif

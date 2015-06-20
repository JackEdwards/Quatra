#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <SFML/Graphics.hpp>
#include "ComponentType.hpp"

class Component
{
public:
    //ComponentType m_type;

public:
    virtual ~Component() = 0;
};

inline Component::~Component() {};

typedef std::shared_ptr<Component> ComponentPtr;

#endif

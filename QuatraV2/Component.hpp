#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <SFML/Graphics.hpp>
#include "ComponentType.hpp"

class Component
{
public:
    ComponentType _type;

public:
    virtual ~Component() = 0;
};

inline Component::~Component() {};

#endif

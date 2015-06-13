#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <SFML/Graphics.hpp>
#include "ComponentFlag.hpp"

class Component
{
public:
    ComponentFlag _flag;

public:
    virtual ~Component() = 0;
};

inline Component::~Component() {};

#endif

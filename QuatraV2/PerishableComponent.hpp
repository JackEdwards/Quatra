#ifndef PERISHABLECOMPONENT_HPP
#define PERISHABLECOMPONENT_HPP

#include "Component.hpp"

enum PerishCondition
{
    OutOfBounds,
    NoHealth
};

class PerishableComponent : public Component
{
public:
    PerishCondition m_perishCondition;
public:
    PerishableComponent(PerishCondition perishCondition);
};

typedef std::shared_ptr<PerishableComponent> PerishableComponentPtr;

#endif

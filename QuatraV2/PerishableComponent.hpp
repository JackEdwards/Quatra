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
    ComponentType m_type;
    PerishCondition m_perishCondition;

public:
    PerishableComponent();
    void Init(PerishCondition perishCondition);
};

typedef std::shared_ptr<PerishableComponent> PerishableComponentPtr;

#endif

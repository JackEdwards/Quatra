#ifndef PERISHABLECOMPONENT_HPP
#define PERISHABLECOMPONENT_HPP

#include "Component.hpp"

class PerishableComponent : public Component
{
public:
    bool m_shouldPerish;
public:
    PerishableComponent();
};

typedef std::shared_ptr<PerishableComponent> PerishableComponentPtr;

#endif

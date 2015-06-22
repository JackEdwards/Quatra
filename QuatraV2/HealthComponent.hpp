#ifndef HEALTHCOMPONENT_HPP
#define HEALTHCOMPONENT_HPP

#include "Component.hpp"

class HealthComponent : public Component
{
public:
    int m_health;
public:
    HealthComponent();
    void Init(int health);
};

#endif

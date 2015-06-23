#ifndef IMPACTDAMAGECOMPONENT_HPP
#define IMPACTDAMAGECOMPONENT_HPP

#include "Component.hpp"

class ImpactDamageComponent : public Component
{
public:
    int m_damage;

public:
    ImpactDamageComponent();
    void Init(int damage);
};

typedef std::shared_ptr<ImpactDamageComponent> ImpactDamageComponentPtr;

#endif

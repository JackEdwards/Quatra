#ifndef GUNCOMPONENT_HPP
#define GUNCOMPONENT_HPP

#include "Component.hpp"

class GunComponent : public Component
{
public:
    ComponentType m_type;
    sf::Clock m_reloadClock;
    float m_reloadLimit;

public:
    GunComponent();
    void Init(float reloadLimit);
};

typedef std::shared_ptr<GunComponent> GunComponentPtr;

#endif

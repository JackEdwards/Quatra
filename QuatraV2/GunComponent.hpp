#ifndef GUNCOMPONENT_HPP
#define GUNCOMPONENT_HPP

#include "Component.hpp"

class GunComponent : public Component
{
public:
    GunComponent();
};

typedef std::shared_ptr<GunComponent> GunComponentPtr;

#endif

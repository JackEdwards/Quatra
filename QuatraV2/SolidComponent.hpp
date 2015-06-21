#ifndef SOLIDCOMPONENT_HPP
#define SOLIDCOMPONENT_HPP

#include "Component.hpp"

class SolidComponent : public Component
{
public:
    SolidComponent();
};

typedef std::shared_ptr<SolidComponent> SolidComponentPtr;

#endif

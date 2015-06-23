#ifndef RIGIDBODYCOMPONENT_HPP
#define RIGIDBODYCOMPONENT_HPP

#include "Component.hpp"

class RigidBodyComponent : public Component
{
public:
    RigidBodyComponent();
};

typedef std::shared_ptr<RigidBodyComponent> RigidBodyComponentPtr;

#endif

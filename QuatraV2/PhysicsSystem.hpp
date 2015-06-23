#ifndef PHYSICSSYSTEM_HPP
#define PHYSICSSYSTEM_HPP

#include <math.h>
#include "System.hpp"
#include "VelocityComponent.hpp"
#include "SpriteComponent.hpp"

class PhysicsSystem : public System
{
public:
    PhysicsSystem();
    void Update(EntityPtrList& entities, float deltaTime);
};

#endif

#ifndef COLLISIONSYSTEM_HPP
#define COLLISIONSYSTEM_HPP

#include <iostream>
#include "System.hpp"
#include "SpriteComponent.hpp"
#include "VelocityComponent.hpp"

class CollisionSystem : public System
{
public:
    CollisionSystem();
    void Update(EntityPtrList& entities);
};

#endif

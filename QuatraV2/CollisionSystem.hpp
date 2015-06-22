#ifndef COLLISIONSYSTEM_HPP
#define COLLISIONSYSTEM_HPP

#include "System.hpp"
#include "SpriteComponent.hpp"
#include "VelocityComponent.hpp"
#include "HealthComponent.hpp"
#include "ImpactDamageComponent.hpp"

class CollisionSystem : public System
{
public:
    CollisionSystem();
    void Update(EntityPtrList& entities);
};

#endif

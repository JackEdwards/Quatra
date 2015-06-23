#ifndef DESTRUCTIONSYSTEM_HPP
#define DESTRUCTIONSYSTEM_HPP

#include "System.hpp"
#include "TransformComponent.hpp"
#include "PerishableComponent.hpp"

class DestructionSystem : public System
{
public:
    DestructionSystem();
    void Update(EntityPtrList& entities);
};

#endif

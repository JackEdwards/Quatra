#ifndef DESTRUCTIONSYSTEM_HPP
#define DESTRUCTIONSYSTEM_HPP

#include <iostream>
#include "System.hpp"
#include "SpriteComponent.hpp"
#include "PerishableComponent.hpp"

class DestructionSystem : public System
{
public:
    DestructionSystem();
    void Update(EntityPtrList& entities);
};

#endif

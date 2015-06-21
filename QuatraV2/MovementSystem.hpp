#ifndef MOVEMENTSYSTEM_HPP
#define MOVEMENTSYSTEM_HPP

#include "Math.hpp"
#include "System.hpp"
#include "VelocityComponent.hpp"
#include "InputComponent.hpp"

class MovementSystem : public System
{
public:
    MovementSystem();
    void Update(EntityPtrList& entities);
};

#endif

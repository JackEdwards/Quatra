#ifndef MOVEMENTSYSTEM_HPP
#define MOVEMENTSYSTEM_HPP

#include "System.hpp"
#include "VelocityComponent.hpp"
#include "InputComponent.hpp"

class MovementSystem : public System
{
public:
    MovementSystem();
    virtual void VUpdate(std::vector<Entity*> entities);
};

#endif

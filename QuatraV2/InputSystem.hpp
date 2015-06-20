#ifndef INPUTSYSTEM_HPP
#define INPUTSYSTEM_HPP

#include "System.hpp"
#include "InputComponent.hpp"
#include "VelocityComponent.hpp"

class InputSystem : public System
{
public:
    InputSystem();
    void Update(EntityPtrList& entities);
};

#endif

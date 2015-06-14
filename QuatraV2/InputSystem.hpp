#ifndef INPUTSYSTEM_HPP
#define INPUTSYSTEM_HPP

#include "System.hpp"
#include "InputComponent.hpp"

class InputSystem : public System
{
public:
    InputSystem();
    virtual void VUpdate(EntityPtrList entities) override;
};

#endif

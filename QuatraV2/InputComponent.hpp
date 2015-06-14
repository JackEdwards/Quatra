#ifndef INPUTCOMPONENT_HPP
#define INPUTCOMPONENT_HPP

#include "Component.hpp"

class InputComponent : public Component
{
public:
    bool _moveUpKeyPressed;
    bool _moveDownKeyPressed;
    bool _moveLeftKeyPressed;
    bool _moveRightKeyPressed;

public:
    InputComponent();
};

typedef std::shared_ptr<InputComponent> InputComponentPtr;

#endif

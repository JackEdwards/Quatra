#include "InputComponent.hpp"

InputComponent::InputComponent()
{
    _type = ComponentType::Input;

    _moveUpKeyPressed    = false;
    _moveDownKeyPressed  = false;
    _moveLeftKeyPressed  = false;
    _moveRightKeyPressed = false;
}
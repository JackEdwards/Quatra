#include "InputComponent.hpp"

InputComponent::InputComponent()
{
    _flag = ComponentFlag::Input;

    _moveUpKeyPressed    = false;
    _moveDownKeyPressed  = false;
    _moveLeftKeyPressed  = false;
    _moveRightKeyPressed = false;
}
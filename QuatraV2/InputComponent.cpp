#include "InputComponent.hpp"

InputComponent::InputComponent()
{
    m_type = ComponentType::Input;
}

void InputComponent::Init()
{
    m_moveUpKeyPressed    = false;
    m_moveDownKeyPressed  = false;
    m_moveLeftKeyPressed  = false;
    m_moveRightKeyPressed = false;
    m_fireKeyPressed      = false;
}
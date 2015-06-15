#include "InputComponent.hpp"

InputComponent::InputComponent()
{
    m_type = ComponentType::Input;

    m_moveUpKeyPressed    = false;
    m_moveDownKeyPressed  = false;
    m_moveLeftKeyPressed  = false;
    m_moveRightKeyPressed = false;
    m_fireKeyPressed      = false;
}
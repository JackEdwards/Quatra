#include "InputSystem.hpp"

InputSystem::InputSystem()
{
    m_lock = ComponentType::Input;
}

void InputSystem::Update(EntityPtrList& entities)
{
    for (EntityPtr& entity : entities) {
        if (KeyFitsLock(entity->m_types)) {
            InputComponentPtr p_input = std::static_pointer_cast<InputComponent>(entity->GetComponent(ComponentType::Input));

            p_input->m_moveUpKeyPressed    = (sf::Keyboard::isKeyPressed(sf::Keyboard::W))     ? true : false;
            p_input->m_moveDownKeyPressed  = (sf::Keyboard::isKeyPressed(sf::Keyboard::S))     ? true : false;
            p_input->m_moveLeftKeyPressed  = (sf::Keyboard::isKeyPressed(sf::Keyboard::A))     ? true : false;
            p_input->m_moveRightKeyPressed = (sf::Keyboard::isKeyPressed(sf::Keyboard::D))     ? true : false;
            p_input->m_fireKeyPressed      = (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) ? true : false;
        }
    }
}
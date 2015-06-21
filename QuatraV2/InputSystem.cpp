#include "InputSystem.hpp"

InputSystem::InputSystem()
{
    m_lock = ComponentType::Input;
}

void InputSystem::Update(EntityPtrList& entities)
{
    for (EntityPtr& p_entity : entities) {
        if (KeyFitsLock(p_entity->m_types)) {
            InputComponentPtr p_input = p_entity->GetComponent<InputComponent>();

            p_input->m_moveUpKeyPressed    = (sf::Keyboard::isKeyPressed(sf::Keyboard::W))     ? true : false;
            p_input->m_moveDownKeyPressed  = (sf::Keyboard::isKeyPressed(sf::Keyboard::S))     ? true : false;
            p_input->m_moveLeftKeyPressed  = (sf::Keyboard::isKeyPressed(sf::Keyboard::A))     ? true : false;
            p_input->m_moveRightKeyPressed = (sf::Keyboard::isKeyPressed(sf::Keyboard::D))     ? true : false;
            p_input->m_fireKeyPressed      = (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) ? true : false;
        }
    }
}
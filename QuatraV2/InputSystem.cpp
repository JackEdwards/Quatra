#include "InputSystem.hpp"

InputSystem::InputSystem()
{
    _lock = ComponentType::Input;
}

void InputSystem::VUpdate(EntityPtrList entities)
{
    for (EntityPtr entity : entities) {
        if (KeyFitsLock(entity->_types)) {
            InputComponentPtr input = std::dynamic_pointer_cast<InputComponent>(entity->GetComponent(ComponentType::Input));
            
            input->_moveUpKeyPressed    = (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) ? true : false;
            input->_moveDownKeyPressed  = (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) ? true : false;
            input->_moveLeftKeyPressed  = (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) ? true : false;
            input->_moveRightKeyPressed = (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) ? true : false;
        }
    }
}
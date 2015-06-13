#include "InputSystem.hpp"

InputSystem::InputSystem()
{
    _flags = ComponentFlag::Input;
}

void InputSystem::VUpdate(std::vector<Entity*> entities)
{
    for (Entity* entity : entities) {
        if ((entity->_flags & _flags) == _flags) {
            InputComponent* input = dynamic_cast<InputComponent*>(entity->_components[ComponentFlag::Input]);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                input->_moveUpKeyPressed = true;
            }
            else {
                input->_moveUpKeyPressed = false;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                input->_moveDownKeyPressed = true;
            }
            else {
                input->_moveDownKeyPressed = false;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                input->_moveLeftKeyPressed = true;
            }
            else {
                input->_moveLeftKeyPressed = false;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                input->_moveRightKeyPressed = true;
            }
            else {
                input->_moveRightKeyPressed = false;
            }
        }
    }
}
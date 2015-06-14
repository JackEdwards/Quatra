#include "InputSystem.hpp"

InputSystem::InputSystem()
{
    _types = ComponentType::Input;
}

void InputSystem::VUpdate(std::vector<Entity*> entities)
{
    for (Entity* entity : entities) {
        if ((entity->_types & _types) == _types) {
            InputComponent* input = dynamic_cast<InputComponent*>(entity->GetComponent(ComponentType::Input));

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
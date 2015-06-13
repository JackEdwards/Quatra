#include "MovementSystem.hpp"

MovementSystem::MovementSystem()
{
    _flags = ComponentFlag::Velocity | ComponentFlag::Input;
}

void MovementSystem::VUpdate(std::vector<Entity*> entities)
{
    for (Entity* entity : entities) {
        if ((entity->_flags & _flags) == _flags) {
            VelocityComponent* velocity = dynamic_cast<VelocityComponent*>(entity->_components[ComponentFlag::Velocity]);
            InputComponent* input = dynamic_cast<InputComponent*>(entity->_components[ComponentFlag::Input]);

            if (input->_moveUpKeyPressed) {
                velocity->_velocity.y = -velocity->_acceleration;
            }
            if (input->_moveDownKeyPressed) {
                velocity->_velocity.y = velocity->_acceleration;
            }
            if (input->_moveLeftKeyPressed) {
                velocity->_velocity.x = -velocity->_acceleration;
            }
            if (input->_moveRightKeyPressed) {
                velocity->_velocity.x = velocity->_acceleration;
            }
        }
    }
}
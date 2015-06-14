#include "MovementSystem.hpp"

MovementSystem::MovementSystem()
{
    _types = ComponentType::Velocity | ComponentType::Input;
}

void MovementSystem::VUpdate(std::vector<Entity*> entities)
{
    for (Entity* entity : entities) {
        if ((entity->_types & _types) == _types) {
            VelocityComponent* velocity = dynamic_cast<VelocityComponent*>(entity->GetComponent(ComponentType::Velocity));
            InputComponent* input = dynamic_cast<InputComponent*>(entity->GetComponent(ComponentType::Input));

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
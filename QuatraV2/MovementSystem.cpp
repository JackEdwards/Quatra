#include "MovementSystem.hpp"

MovementSystem::MovementSystem()
{
    _lock = ComponentType::Velocity | ComponentType::Input;
}

void MovementSystem::VUpdate(EntityPtrList entities)
{
    for (EntityPtr entity : entities) {
        if (KeyFitsLock(entity->_types)) {
            VelocityComponentPtr velocity = std::dynamic_pointer_cast<VelocityComponent>(entity->GetComponent(ComponentType::Velocity));
            InputComponentPtr input = std::dynamic_pointer_cast<InputComponent>(entity->GetComponent(ComponentType::Input));

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
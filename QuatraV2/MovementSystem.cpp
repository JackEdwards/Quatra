#include "MovementSystem.hpp"

MovementSystem::MovementSystem()
{
    m_lock = ComponentType::Velocity | ComponentType::Input;
}

void MovementSystem::Update(EntityPtrList& entities)
{
    for (EntityPtr entity : entities) {
        if (KeyFitsLock(entity->m_types)) {
            VelocityComponentPtr p_velocity = std::dynamic_pointer_cast<VelocityComponent>(entity->GetComponent(ComponentType::Velocity));
            InputComponentPtr p_input = std::dynamic_pointer_cast<InputComponent>(entity->GetComponent(ComponentType::Input));

            p_velocity->m_velocity = sf::Vector2f(0.0, 0.0);
            
            if (p_input->m_moveUpKeyPressed) {
                p_velocity->m_velocity.y = -p_velocity->m_acceleration;
            }
            if (p_input->m_moveDownKeyPressed) {
                p_velocity->m_velocity.y = p_velocity->m_acceleration;
            }
            if (p_input->m_moveLeftKeyPressed) {
                p_velocity->m_velocity.x = -p_velocity->m_acceleration;
            }
            if (p_input->m_moveRightKeyPressed) {
                p_velocity->m_velocity.x = p_velocity->m_acceleration;
            }
        }
    }
}
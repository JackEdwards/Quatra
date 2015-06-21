#include "MovementSystem.hpp"

MovementSystem::MovementSystem()
{
    m_lock = ComponentType::Velocity | ComponentType::Input;
}

void MovementSystem::Update(EntityPtrList& entities)
{
    for (EntityPtr& p_entity : entities) {
        if (KeyFitsLock(p_entity->m_types)) {
            VelocityComponentPtr p_velocity = p_entity->GetComponent<VelocityComponent>();
            InputComponentPtr p_input = p_entity->GetComponent<InputComponent>();

            p_velocity->m_velocity = sf::Vector2f(0.0, 0.0);
            
            if (p_input->m_moveUpKeyPressed) {
                p_velocity->m_velocity.y = -1.0f;
                p_velocity->m_velocity = Normalize(p_velocity->m_velocity);
            }
            if (p_input->m_moveDownKeyPressed) {
                p_velocity->m_velocity.y = 1.0f;
                p_velocity->m_velocity = Normalize(p_velocity->m_velocity);
            }
            if (p_input->m_moveLeftKeyPressed) {
                p_velocity->m_velocity.x = -1.0f;
                p_velocity->m_velocity = Normalize(p_velocity->m_velocity);
            }
            if (p_input->m_moveRightKeyPressed) {
                p_velocity->m_velocity.x = 1.0f;
                p_velocity->m_velocity = Normalize(p_velocity->m_velocity);
            }
        }
    }
}
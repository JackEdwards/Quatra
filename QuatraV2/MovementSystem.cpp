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
            sf::Vector2f& velocity = p_velocity->m_velocity;

            velocity = sf::Vector2f(0.0, 0.0);
            
            if (p_input->m_moveUpKeyPressed) {
                velocity.y = -1.0f;
                velocity = Normalize(velocity);
            }
            if (p_input->m_moveDownKeyPressed) {
                velocity.y = 1.0f;
                velocity = Normalize(velocity);
            }
            if (p_input->m_moveLeftKeyPressed) {
                velocity.x = -1.0f;
                velocity = Normalize(velocity);
            }
            if (p_input->m_moveRightKeyPressed) {
                velocity.x = 1.0f;
                velocity = Normalize(velocity);
            }
        }
    }
}
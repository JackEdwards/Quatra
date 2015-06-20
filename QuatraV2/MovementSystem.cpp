#include "MovementSystem.hpp"

MovementSystem::MovementSystem()
{
    m_lock = ComponentType::Velocity | ComponentType::Input;
}

void MovementSystem::Update(EntityPtrList& entities)
{
    for (EntityPtr& p_entity : entities) {
        if (KeyFitsLock(p_entity->m_types)) {
            VelocityComponentPtr p_velocityComp = std::static_pointer_cast<VelocityComponent>(p_entity->GetComponent(ComponentType::Velocity));
            InputComponentPtr p_inputComp = std::static_pointer_cast<InputComponent>(p_entity->GetComponent(ComponentType::Input));

            p_velocityComp->m_velocity = sf::Vector2f(0.0, 0.0);
            
            if (p_inputComp->m_moveUpKeyPressed) {
                p_velocityComp->m_velocity.y = -1.0f;
            }
            if (p_inputComp->m_moveDownKeyPressed) {
                p_velocityComp->m_velocity.y = 1.0f;
            }
            if (p_inputComp->m_moveLeftKeyPressed) {
                p_velocityComp->m_velocity.x = -1.0f;
            }
            if (p_inputComp->m_moveRightKeyPressed) {
                p_velocityComp->m_velocity.x = 1.0f;
            }
        }
    }
}
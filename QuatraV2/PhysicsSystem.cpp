#include "PhysicsSystem.hpp"

PhysicsSystem::PhysicsSystem()
{
    m_lock = ComponentType::Velocity | ComponentType::Transform;
}

void PhysicsSystem::Update(EntityPtrList& entities, float dt)
{
    for (EntityPtr& p_entity : entities) {
        if (KeyFitsLock(p_entity->m_types)) {
            VelocityComponentPtr p_velocity = p_entity->GetComponent<VelocityComponent>();
            TransformComponentPtr p_transform = p_entity->GetComponent<TransformComponent>();
            
            sf::Vector2f velocity = p_velocity->m_velocity;
            float speed = p_velocity->m_speed;

            sf::Vector2f offset = (velocity * dt) * speed;
            p_transform->m_position = p_transform->m_position + offset;
        }
    }
}
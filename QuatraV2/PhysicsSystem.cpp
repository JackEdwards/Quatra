#include "PhysicsSystem.hpp"

PhysicsSystem::PhysicsSystem()
{
    m_lock = ComponentType::Velocity | ComponentType::Sprite;
}

void PhysicsSystem::Update(EntityPtrList& entities, float dt)
{
    for (EntityPtr& p_entity : entities) {
        if (KeyFitsLock(p_entity->m_types)) {
            VelocityComponentPtr p_velocity = p_entity->GetComponent<VelocityComponent>();
            SpriteComponentPtr p_sprite = p_entity->GetComponent<SpriteComponent>();
            
            sf::Vector2f velocity = p_velocity->m_velocity;
            float speed = p_velocity->m_speed;

            sf::Vector2f offset = (velocity * dt) * speed;
            p_sprite->m_sprite.move(offset);
        }
    }
}
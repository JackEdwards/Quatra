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

            p_sprite->m_sprite.move((p_velocity->m_velocity * dt) * p_velocity->m_speed);
        }
    }
}
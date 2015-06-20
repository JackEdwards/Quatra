#include "PhysicsSystem.hpp"

PhysicsSystem::PhysicsSystem()
{
    m_lock = ComponentType::Velocity | ComponentType::Sprite;
}

void PhysicsSystem::Update(EntityPtrList& entities, float dt)
{
    for (EntityPtr& p_entity : entities) {
        if (KeyFitsLock(p_entity->m_types)) {
            VelocityComponentPtr p_velocityComp = p_entity->GetComponent<VelocityComponent>();
            SpriteComponentPtr p_spriteComp = p_entity->GetComponent<SpriteComponent>();

            p_spriteComp->m_sprite.move((p_velocityComp->m_velocity * dt) * p_velocityComp->m_speed);
        }
    }
}
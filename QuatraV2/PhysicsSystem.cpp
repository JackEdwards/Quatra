#include "PhysicsSystem.hpp"

PhysicsSystem::PhysicsSystem()
{
    m_lock = ComponentType::Velocity | ComponentType::Sprite;
}

void PhysicsSystem::Update(EntityPtrList& entities, float dt)
{
    for (EntityPtr& p_entity : entities) {
        if (KeyFitsLock(p_entity->m_types)) {
            VelocityComponentPtr p_velocityComp = std::static_pointer_cast<VelocityComponent>(p_entity->GetComponent(ComponentType::Velocity));
            SpriteComponentPtr p_spriteComp = std::static_pointer_cast<SpriteComponent>(p_entity->GetComponent(ComponentType::Sprite));

            p_spriteComp->m_sprite.move(((p_velocityComp->m_velocity * dt) * p_velocityComp->m_speed));
        }
    }
}
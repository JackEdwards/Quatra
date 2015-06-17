#include "PhysicsSystem.hpp"

PhysicsSystem::PhysicsSystem()
{
    m_lock = ComponentType::Velocity | ComponentType::Sprite;
}

void PhysicsSystem::Update(EntityPtrList& entities, float dt)
{
    for (EntityPtr& entity : entities) {
        if (KeyFitsLock(entity->m_types)) {
            VelocityComponentPtr p_velocity = std::static_pointer_cast<VelocityComponent>(entity->GetComponent(ComponentType::Velocity));
            SpriteComponentPtr p_sprite = std::static_pointer_cast<SpriteComponent>(entity->GetComponent(ComponentType::Sprite));

            p_sprite->m_sprite.move(p_velocity->m_velocity * dt);
        }
    }
}
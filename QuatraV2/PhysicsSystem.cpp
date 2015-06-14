#include "PhysicsSystem.hpp"

PhysicsSystem::PhysicsSystem()
{
    _lock = ComponentType::Velocity | ComponentType::Sprite;
}

void PhysicsSystem::VUpdate(EntityPtrList entities)
{
    for (EntityPtr entity : entities) {
        if (KeyFitsLock(entity->_types)) {
            VelocityComponentPtr velocity = std::dynamic_pointer_cast<VelocityComponent>(entity->GetComponent(ComponentType::Velocity));
            SpriteComponentPtr sprite = std::dynamic_pointer_cast<SpriteComponent>(entity->GetComponent(ComponentType::Sprite));
            
            sprite->_sprite.move(velocity->_velocity);

            velocity->_velocity = sf::Vector2f(0.0, 0.0);
        }
    }
}
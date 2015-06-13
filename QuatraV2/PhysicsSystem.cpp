#include "PhysicsSystem.hpp"

PhysicsSystem::PhysicsSystem()
{
    _flags = ComponentFlag::Velocity | ComponentFlag::Sprite;
}

void PhysicsSystem::VUpdate(std::vector<Entity *> entities)
{
    for (Entity* entity : entities) {
        if ((entity->_flags & _flags) == _flags) {
            VelocityComponent* velocity = dynamic_cast<VelocityComponent*>(entity->_components[ComponentFlag::Velocity]);
            SpriteComponent* sprite = dynamic_cast<SpriteComponent*>(entity->_components[ComponentFlag::Sprite]);
            
            sprite->_sprite.move(velocity->_velocity);
            velocity->_velocity = sf::Vector2f(0.0, 0.0);
        }
    }
}
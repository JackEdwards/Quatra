#include "PhysicsSystem.hpp"

PhysicsSystem::PhysicsSystem()
{
    _types = ComponentType::Velocity | ComponentType::Sprite;
}

void PhysicsSystem::VUpdate(std::vector<Entity*> entities)
{
    for (Entity* entity : entities) {
        if ((entity->_types & _types) == _types) {
            VelocityComponent* velocity = dynamic_cast<VelocityComponent*>(entity->GetComponent(ComponentType::Velocity));
            SpriteComponent* sprite = dynamic_cast<SpriteComponent*>(entity->GetComponent(ComponentType::Sprite));
            
            sprite->_sprite.move(velocity->_velocity);
            velocity->_velocity = sf::Vector2f(0.0, 0.0);
        }
    }
}
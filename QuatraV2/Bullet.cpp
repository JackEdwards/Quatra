#include "Bullet.hpp"

Bullet::Bullet(sf::Vector2f position, sf::Vector2f velocity, float rotation)
{
    AddComponent<TransformComponent>();
    AddComponent<TextureComponent>();
    AddComponent<VelocityComponent>();
    AddComponent<PerishableComponent>();
    AddComponent<RigidBodyComponent>();
    
    GetComponent<TransformComponent>()->Init(position);
    GetComponent<TextureComponent>()->Init(ResourceManager::BulletTexture);
    GetComponent<VelocityComponent>()->Init(velocity, Settings::BulletSpeed);
    GetComponent<PerishableComponent>()->Init(PerishCondition::OutOfBounds);
}
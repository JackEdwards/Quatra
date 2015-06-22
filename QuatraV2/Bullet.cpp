#include "Bullet.hpp"

Bullet::Bullet(sf::Vector2f position, sf::Vector2f velocity, float rotation)
{
    AddComponent<SpriteComponent>();
    AddComponent<VelocityComponent>();
    AddComponent<PerishableComponent>();
    AddComponent<RigidBodyComponent>();
    
    GetComponent<SpriteComponent>()->Init(ResourceManager::m_bulletTexture, position, Settings::BulletLayerDepth, rotation);
    GetComponent<VelocityComponent>()->Init(velocity, Settings::BulletSpeed);
    GetComponent<PerishableComponent>()->Init(PerishCondition::OutOfBounds);
    
    GetComponent<SpriteComponent>()->SetCentreOrigin();
}
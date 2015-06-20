#include "Bullet.hpp"

Bullet::Bullet(sf::Vector2f position, sf::Vector2f velocity, float rotation)
{
    AddComponent<SpriteComponent>();
    AddComponent<VelocityComponent>();
    AddComponent<PerishableComponent>();
    
    GetComponent<SpriteComponent>()->Init(ResourceManager::m_bulletTexture, position, rotation);
    GetComponent<VelocityComponent>()->Init(velocity, 3.0f);
    GetComponent<PerishableComponent>()->Init(PerishCondition::OutOfBounds);
    
    SpriteComponentPtr p_spriteComp = GetComponent<SpriteComponent>();
    sf::Vector2u textureSize = p_spriteComp->m_sprite.getTexture()->getSize();
    p_spriteComp->m_sprite.setOrigin(textureSize.x / 2, textureSize.x / 2);
}
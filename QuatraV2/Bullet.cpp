#include "Bullet.hpp"

Bullet::Bullet(sf::Vector2f position, sf::Vector2f velocity, float rotation)
{
    AddComponent(std::make_shared<SpriteComponent>(ResourceManager::m_bulletTexture, position, rotation));
    AddComponent(std::make_shared<VelocityComponent>(velocity, 3.0f));
    AddComponent(std::make_shared<PerishableComponent>(PerishCondition::OutOfBounds));
    
    SpriteComponentPtr p_spriteComp = std::static_pointer_cast<SpriteComponent>(GetComponent(ComponentType::Sprite));
    
    sf::Vector2u textureSize = p_spriteComp->m_sprite.getTexture()->getSize();
    p_spriteComp->m_sprite.setOrigin(textureSize.x / 2, textureSize.x / 2);
}
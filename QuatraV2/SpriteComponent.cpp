#include "SpriteComponent.hpp"

SpriteComponent::SpriteComponent(sf::Texture& texture, sf::Vector2f position, float rotation)
{
    m_type = ComponentType::Sprite;
    
    m_sprite.setTexture(texture);
    m_sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    m_sprite.setPosition(position);
    m_sprite.setRotation(rotation);
}
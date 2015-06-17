#include "SpriteComponent.hpp"

SpriteComponent::SpriteComponent(std::string fileName, sf::Vector2f position, float rotation)
{
    m_type = ComponentType::Sprite;
    
    m_texture.loadFromFile(resourcePath() + fileName);
    m_sprite.setTexture(m_texture);
    m_sprite.setOrigin(m_texture.getSize().x / 2, m_texture.getSize().y / 2);
    m_sprite.setPosition(position);
    m_sprite.setRotation(rotation);
}
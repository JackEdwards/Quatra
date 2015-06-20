#include "SpriteComponent.hpp"

SpriteComponent::SpriteComponent()
{
    m_type = ComponentType::Sprite;
}

void SpriteComponent::Init(sf::Texture &texture, sf::Vector2f position, float rotation)
{
    m_sprite.setTexture(texture);
    m_sprite.setPosition(position);
    m_sprite.setRotation(rotation);
}
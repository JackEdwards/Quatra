#include "SpriteComponent.hpp"

SpriteComponent::SpriteComponent()
{
    m_type = ComponentType::Sprite;
}

void SpriteComponent::Init(sf::Vector2f position, sf::Texture &texture)
{
    m_sprite.setPosition(position);
    m_sprite.setTexture(texture);
}

void SpriteComponent::Init(sf::Vector2f position, sf::Texture &texture, sf::IntRect rect)
{
    m_sprite.setPosition(position);
    m_sprite.setTexture(texture);
    m_sprite.setTextureRect(rect);
}

void SpriteComponent::Init(sf::Vector2f position, sf::Texture &texture, float rotation)
{
    m_sprite.setPosition(position);
    m_sprite.setTexture(texture);
    m_sprite.setRotation(rotation);
}

void SpriteComponent::SetCenterOrigin()
{
    sf::IntRect rect = m_sprite.getTextureRect();
    m_sprite.setOrigin(rect.width / 2, rect.height / 2);
}
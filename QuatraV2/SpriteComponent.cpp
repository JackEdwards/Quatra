#include "SpriteComponent.hpp"

SpriteComponent::SpriteComponent()
{
    m_type = ComponentType::Sprite;
}

void SpriteComponent::Init(sf::Texture &texture, sf::Vector2f position, int depth, float rotation)
{
    if (depth < MIN_DEPTH || depth > MAX_DEPTH) {
        throw std::out_of_range("Depth must be between " + std::to_string(MIN_DEPTH) + " and " + std::to_string(MAX_DEPTH) + ".\n");
    }

    m_sprite.setTexture(texture);
    m_sprite.setPosition(position);
    m_sprite.setRotation(rotation);
    m_depth = depth;
}
/*#include "TextureComponent.hpp"

TextureComponent::TextureComponent()
{
    m_type = ComponentType::Texture;
}

void TextureComponent::Init(sf::Texture &texture)
{
    m_texture = texture;
    sf::Vector2u size = texture.getSize();
    m_sourceRect = sf::IntRect(0, 0, size.x, size.y);
}

void TextureComponent::Init(sf::Texture& texture, sf::IntRect rect)
{
    m_texture = texture;
    m_sourceRect = rect;
}*/
#include "SpriteComponent.hpp"

SpriteComponent::SpriteComponent(std::string fileName)
{
    _type = ComponentType::Sprite;

    _texture.loadFromFile(resourcePath() + fileName);
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_texture.getSize().x / 2, _texture.getSize().y / 2);
}

SpriteComponent::SpriteComponent(std::string fileName, sf::Vector2f position)
{
    _type = ComponentType::Sprite;
    
    _texture.loadFromFile(resourcePath() + fileName);
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_texture.getSize().x / 2, _texture.getSize().y / 2);
    _sprite.setPosition(position);
}
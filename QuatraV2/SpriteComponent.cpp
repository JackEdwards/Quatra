#include "SpriteComponent.hpp"

SpriteComponent::SpriteComponent(std::string fileName)
{
    _flag = ComponentFlag::Sprite;

    _texture.loadFromFile(resourcePath() + fileName);
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_texture.getSize().x / 2, _texture.getSize().y / 2);
}
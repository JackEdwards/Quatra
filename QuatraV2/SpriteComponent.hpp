#ifndef SPRITECOMPONENT_HPP
#define SPRITECOMPONENT_HPP

#include "ResourcePath.hpp"
#include "Component.hpp"

class SpriteComponent : public Component
{
public:
    sf::Texture _texture;
    sf::Sprite _sprite;

public:
    SpriteComponent(std::string fileName);
};

#endif

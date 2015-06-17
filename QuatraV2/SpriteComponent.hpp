#ifndef SPRITECOMPONENT_HPP
#define SPRITECOMPONENT_HPP

#include "ResourcePath.hpp"
#include "Component.hpp"

class SpriteComponent : public Component
{
public:
    sf::Sprite m_sprite;

public:
    SpriteComponent(sf::Texture& texture, sf::Vector2f position, float rotation = 0);
};

typedef std::shared_ptr<SpriteComponent> SpriteComponentPtr;

#endif

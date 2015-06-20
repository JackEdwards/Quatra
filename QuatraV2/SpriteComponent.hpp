#ifndef SPRITECOMPONENT_HPP
#define SPRITECOMPONENT_HPP

#include "ResourcePath.hpp"
#include "Component.hpp"

class SpriteComponent : public Component
{
public:
    ComponentType m_type;
    sf::Sprite m_sprite;

public:
    SpriteComponent();
    void Init(sf::Texture& texture, sf::Vector2f position, float rotation = 0);
};

typedef std::shared_ptr<SpriteComponent> SpriteComponentPtr;

#endif

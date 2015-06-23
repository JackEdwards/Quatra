#ifndef SPRITECOMPONENT_HPP
#define SPRITECOMPONENT_HPP

#include "Component.hpp"

class SpriteComponent : public Component
{
public:
    sf::Sprite m_sprite;

public:
    SpriteComponent();
    void Init(sf::Vector2f position, sf::Texture& texture);
    void Init(sf::Vector2f position, sf::Texture& texture, sf::IntRect sourceRect);
    void Init(sf::Vector2f position, sf::Texture& texture, float rotation);
    void SetCenterOrigin();
};

typedef std::shared_ptr<SpriteComponent> SpriteComponentPtr;

#endif

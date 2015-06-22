#ifndef SPRITECOMPONENT_HPP
#define SPRITECOMPONENT_HPP

#include "ResourcePath.hpp"
#include "Component.hpp"

class SpriteComponent : public Component
{
public:
    sf::Sprite m_sprite;
    int m_depth;
    static const int MIN_DEPTH = 0;
    static const int MAX_DEPTH = 5;

public:
    SpriteComponent();
    void Init(sf::Texture& texture, sf::Vector2f position, int depth, float rotation = 0);
    void SetCentreOrigin();
};

typedef std::shared_ptr<SpriteComponent> SpriteComponentPtr;

#endif

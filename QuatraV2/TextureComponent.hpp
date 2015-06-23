/*#ifndef TEXTURECOMPONENT_HPP
#define TEXTURECOMPONENT_HPP

#include "Component.hpp"

class TextureComponent : public Component
{
public:
    sf::Texture m_texture;
    sf::IntRect m_sourceRect;

public:
    TextureComponent();
    void Init(sf::Texture& texture);
    void Init(sf::Texture& texture, sf::IntRect sourceRect);
};

typedef std::shared_ptr<TextureComponent> TextureComponentPtr;

#endif
*/
#ifndef SPRITEBATCH_HPP
#define SPRITEBATCH_HPP

#include "ResourceManager.hpp"
#include <SFML/Graphics.hpp>

class SpriteBatch
{
private:
    sf::VertexArray m_vertices;
    sf::Texture* m_spritesheet;
    sf::RenderStates m_states;

public:
    SpriteBatch();
    void Begin();
    void Draw(sf::Sprite sprite);
    void End(sf::RenderWindow& window);
};

#endif

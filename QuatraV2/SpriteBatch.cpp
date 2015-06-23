#include "SpriteBatch.hpp"

SpriteBatch::SpriteBatch()
{
    m_spritesheet = &ResourceManager::Spritesheet;
}

void SpriteBatch::Begin()
{
    m_vertices.clear();
    m_vertices.setPrimitiveType(sf::Quads);
}

void SpriteBatch::Draw(sf::Sprite sprite)
{
    m_vertices.resize(m_vertices.getVertexCount() + 4);

    sf::Vertex* quad = &m_vertices[m_vertices.getVertexCount() - 4];
    sf::IntRect rect = sprite.getTextureRect();

    sf::Vector2f topLeft = sprite.getTransform().transformPoint(sf::Vector2f(0.0f, 0.0f));
    sf::Vector2f topRight = sprite.getTransform().transformPoint(sf::Vector2f(rect.width, 0.0f));
    sf::Vector2f bottomRight = sprite.getTransform().transformPoint(sf::Vector2f(rect.width, rect.height));
    sf::Vector2f bottomLeft = sprite.getTransform().transformPoint(sf::Vector2f(0.0f, rect.height));
    
    quad[0].position = topLeft;
    quad[1].position = topRight;
    quad[2].position = bottomRight;
    quad[3].position = bottomLeft;
    
    quad[0].texCoords = sf::Vector2f(rect.left, rect.top);
    quad[1].texCoords = sf::Vector2f(rect.left + rect.width, rect.top);
    quad[2].texCoords = sf::Vector2f(rect.left + rect.width, rect.top + rect.height);
    quad[3].texCoords = sf::Vector2f(rect.left, rect.top + rect.height);
}

void SpriteBatch::End(sf::RenderWindow& window)
{
    m_states.texture = m_spritesheet;
    window.draw(m_vertices, m_states);
}
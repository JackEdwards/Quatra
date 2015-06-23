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

void SpriteBatch::Draw(sf::Vector2f position)
{
    m_vertices.resize(m_vertices.getVertexCount() + 4);
    sf::Vertex* quad = &m_vertices[m_vertices.getVertexCount() - 4];
    sf::Vector2u size = m_spritesheet->getSize();

    quad[0].position = sf::Vector2f(position.x, position.y);
    quad[1].position = sf::Vector2f(position.x + size.x, position.y);
    quad[2].position = sf::Vector2f(position.x + size.x, position.y + size.y);
    quad[3].position = sf::Vector2f(position.x, position.y + size.y);
    
    quad[0].texCoords = sf::Vector2f(0.0f, 0.0f);
    quad[1].texCoords = sf::Vector2f(0.0f + size.x, 0.0f);
    quad[2].texCoords = sf::Vector2f(0.0f + size.x, 0.0f + size.y);
    quad[3].texCoords = sf::Vector2f(0.0f, 0.0f + size.y);
}

void SpriteBatch::Draw(sf::Vector2f position, sf::IntRect rect)
{
    m_vertices.resize(m_vertices.getVertexCount() + 4);
    sf::Vertex* quad = &m_vertices[m_vertices.getVertexCount() - 4];
    
    quad[0].position = sf::Vector2f(position.x, position.y);
    quad[1].position = sf::Vector2f(position.x + rect.width, position.y);
    quad[2].position = sf::Vector2f(position.x + rect.width, position.y + rect.height);
    quad[3].position = sf::Vector2f(position.x, position.y + rect.height);
    
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
#include "Tile.hpp"

Tile::Tile(sf::Texture& texture, sf::Vector2f position)
{
    AddComponent<SpriteComponent>();
    GetComponent<SpriteComponent>()->Init(texture, position);
}
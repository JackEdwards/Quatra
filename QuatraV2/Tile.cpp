#include "Tile.hpp"

Tile::Tile(sf::Texture& texture, sf::Vector2f position)
{
    AddComponent(std::make_shared<SpriteComponent>(texture, position));
}
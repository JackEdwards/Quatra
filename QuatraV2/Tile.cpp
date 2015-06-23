#include "Tile.hpp"

Tile::Tile(sf::IntRect sourceRect, sf::Vector2f position)
{
    AddComponent<SpriteComponent>();

    GetComponent<SpriteComponent>()->Init(position, ResourceManager::Spritesheet, sourceRect);
}
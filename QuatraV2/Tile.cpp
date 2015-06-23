#include "Tile.hpp"

Tile::Tile(sf::IntRect sourceRect, sf::Vector2f position)
{
    AddComponent<TransformComponent>();
    AddComponent<TextureComponent>();

    GetComponent<TransformComponent>()->Init(position);
    GetComponent<TextureComponent>()->Init(ResourceManager::Spritesheet, sourceRect);
}
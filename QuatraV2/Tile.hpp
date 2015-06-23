#ifndef TILE_HPP
#define TILE_HPP

#include "Settings.hpp"
#include "ResourceManager.hpp"
#include "Entity.hpp"
#include "SpriteComponent.hpp"

class Tile : public Entity
{
public:
    Tile(sf::IntRect sourceRect, sf::Vector2f position);
};

#endif

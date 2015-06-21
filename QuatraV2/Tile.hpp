#ifndef TILE_HPP
#define TILE_HPP

#include "ResourceManager.hpp"
#include "Entity.hpp"
#include "SpriteComponent.hpp"
#include "SolidComponent.hpp"

class Tile : public Entity
{
public:
    Tile(sf::Texture& texture, sf::Vector2f position);
};

#endif

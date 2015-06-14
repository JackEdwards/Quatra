#ifndef BULLET_HPP
#define BULLET_HPP

#include "Entity.hpp"
#include "SpriteComponent.hpp"
#include "VelocityComponent.hpp"

class Bullet : public Entity
{
public:
    Bullet(sf::Vector2f velocity);
};

#endif

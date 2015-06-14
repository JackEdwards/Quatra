#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Entity.hpp"
#include "SpriteComponent.hpp"
#include "VelocityComponent.hpp"
#include "InputComponent.hpp"
#include "FaceCursorComponent.hpp"

class Enemy : public Entity
{
public:
    Enemy(sf::Vector2f position);
    ~Enemy();
};

#endif

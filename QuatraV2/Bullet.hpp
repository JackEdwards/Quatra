#ifndef BULLET_HPP
#define BULLET_HPP

#include "Settings.hpp"
#include "ResourceManager.hpp"
#include "Entity.hpp"
#include "SpriteComponent.hpp"
#include "VelocityComponent.hpp"
#include "PerishableComponent.hpp"
#include "RigidBodyComponent.hpp"

class Bullet : public Entity
{
public:
    Bullet(sf::Vector2f position, sf::Vector2f velocity, float rotation);
};

#endif

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Settings.hpp"
#include "ResourceManager.hpp"
#include "Entity.hpp"
#include "SpriteComponent.hpp"
#include "VelocityComponent.hpp"
#include "InputComponent.hpp"
#include "FaceCursorComponent.hpp"
#include "RigidBodyComponent.hpp"
#include "ImpactDamageComponent.hpp"

class Enemy : public Entity
{
public:
    Enemy(sf::Vector2f position);
};

#endif

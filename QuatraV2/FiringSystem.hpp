#ifndef FIRINGSYSTEM_HPP
#define FIRINGSYSTEM_HPP

#include "Math.hpp"
#include "System.hpp"
#include "InputComponent.hpp"
#include "SpriteComponent.hpp"
#include "GunComponent.hpp"
#include "Bullet.hpp"

class FiringSystem : public System
{
public:
    FiringSystem();
    void Update(EntityPtrList& entities, sf::Time time);
};

#endif
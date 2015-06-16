#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.hpp"
#include "SpriteComponent.hpp"
#include "VelocityComponent.hpp"
#include "InputComponent.hpp"
#include "FaceCursorComponent.hpp"
#include "GunComponent.hpp"

class Player : public Entity
{
public:
    Player();
};

#endif

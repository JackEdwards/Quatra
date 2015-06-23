#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Settings.hpp"
#include "ResourceManager.hpp"
#include "Entity.hpp"
#include "TransformComponent.hpp"
#include "TextureComponent.hpp"
#include "VelocityComponent.hpp"
#include "InputComponent.hpp"
#include "FaceCursorComponent.hpp"
#include "GunComponent.hpp"
#include "RigidBodyComponent.hpp"
#include "HealthComponent.hpp"

class Player : public Entity
{
public:
    Player();
};

#endif

#include "Player.hpp"

Player::Player()
{
    AddComponent(new SpriteComponent("player.png"));
    AddComponent(new VelocityComponent(0.0, 0.0, 1.0));
    AddComponent(new InputComponent());
    AddComponent(new FaceCursorComponent());
}
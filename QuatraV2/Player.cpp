#include "Player.hpp"

Player::Player()
{
    AddComponent(std::make_shared<SpriteComponent>("player.png", sf::Vector2f(640, 640)));
    AddComponent(std::make_shared<VelocityComponent>(sf::Vector2f(0.0, 0.0), 1.0));
    AddComponent(std::make_shared<InputComponent>());
    AddComponent(std::make_shared<FaceCursorComponent>());
    AddComponent(std::make_shared<GunComponent>());
}
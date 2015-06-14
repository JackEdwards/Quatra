#include "Bullet.hpp"

Bullet::Bullet(sf::Vector2f velocity)
{
    AddComponent(std::make_shared<SpriteComponent>("bullet.png"));
    AddComponent(std::make_shared<VelocityComponent>(velocity, 2.0));
}
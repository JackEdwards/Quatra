#include "Bullet.hpp"

Bullet::Bullet(sf::Vector2f position, sf::Vector2f velocity, float rotation)
{
    AddComponent(std::make_shared<SpriteComponent>("bullet.png", position, rotation));
    AddComponent(std::make_shared<VelocityComponent>(velocity, 1.0f));
    AddComponent(std::make_shared<PerishableComponent>());
}
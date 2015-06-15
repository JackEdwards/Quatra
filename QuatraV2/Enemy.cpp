#include "Enemy.hpp"

Enemy::Enemy(sf::Vector2f position)
{
    AddComponent(std::make_shared<SpriteComponent>("enemy.png", position));
}
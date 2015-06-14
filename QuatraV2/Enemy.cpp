#include "Enemy.hpp"

Enemy::Enemy()
{
    AddComponent(std::make_shared<SpriteComponent>("enemy.png"));
}
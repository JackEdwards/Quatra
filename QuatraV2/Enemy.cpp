#include "Enemy.hpp"

Enemy::Enemy(sf::Vector2f position)
{
    AddComponent(new SpriteComponent("enemy.png", position));
    AddComponent(new FaceCursorComponent());
}

Enemy::~Enemy()
{
    for (auto iter : _components) {
        delete iter.second;
    }
}
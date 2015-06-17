#include "Enemy.hpp"

Enemy::Enemy(sf::Vector2f position)
{
    AddComponent(std::make_shared<SpriteComponent>(ResourceManager::m_enemyTexture, position));
}
#include "Enemy.hpp"

Enemy::Enemy(sf::Vector2f position)
{
    AddComponent<SpriteComponent>();

    GetComponent<SpriteComponent>()->Init(ResourceManager::m_textures[0], position, 2);
}
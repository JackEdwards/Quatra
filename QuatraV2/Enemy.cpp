#include "Enemy.hpp"

Enemy::Enemy(sf::Vector2f position)
{
    AddComponent<SpriteComponent>();
    AddComponent<ImpactDamageComponent>();

    GetComponent<SpriteComponent>()->Init(ResourceManager::m_textures[0], position, Settings::EnemyLayerDepth);
    GetComponent<ImpactDamageComponent>()->Init(Settings::EnemyDamage);
}
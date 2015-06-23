#include "Enemy.hpp"

Enemy::Enemy(sf::Vector2f position)
{
    AddComponent<SpriteComponent>();
    AddComponent<ImpactDamageComponent>();

    GetComponent<SpriteComponent>()->Init(position, ResourceManager::Spritesheet, ResourceManager::SourceRects[0]);
    GetComponent<ImpactDamageComponent>()->Init(Settings::EnemyDamage);
}
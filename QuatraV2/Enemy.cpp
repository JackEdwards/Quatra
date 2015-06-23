#include "Enemy.hpp"

Enemy::Enemy(sf::Vector2f position)
{
    AddComponent<TransformComponent>();
    AddComponent<TextureComponent>();
    AddComponent<ImpactDamageComponent>();

    GetComponent<TransformComponent>()->Init(position);
    GetComponent<TextureComponent>()->Init(ResourceManager::Spritesheet, ResourceManager::SourceRects[0]);
    GetComponent<ImpactDamageComponent>()->Init(Settings::EnemyDamage);
}
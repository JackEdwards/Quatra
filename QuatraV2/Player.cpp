#include "Player.hpp"

Player::Player()
{
    AddComponent<SpriteComponent>();
    AddComponent<VelocityComponent>();
    AddComponent<InputComponent>();
    AddComponent<FaceCursorComponent>();
    AddComponent<GunComponent>();
    AddComponent<RigidBodyComponent>();
    AddComponent<HealthComponent>();

    GetComponent<SpriteComponent>()->Init(Settings::PlayerPosition, ResourceManager::Spritesheet, ResourceManager::SourceRects[2]);
    GetComponent<VelocityComponent>()->Init(Settings::PlayerVelocity, Settings::PlayerSpeed);
    GetComponent<InputComponent>()->Init();
    GetComponent<FaceCursorComponent>()->Init();
    GetComponent<GunComponent>()->Init(Settings::PlayerReloadSpeed);
    GetComponent<HealthComponent>()->Init(Settings::PlayerHealth);
    
    GetComponent<SpriteComponent>()->SetCenterOrigin();
}
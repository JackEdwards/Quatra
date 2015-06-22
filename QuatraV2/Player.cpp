#include "Player.hpp"

Player::Player()
{
    AddComponent<SpriteComponent>();
    AddComponent<VelocityComponent>();
    AddComponent<InputComponent>();
    AddComponent<FaceCursorComponent>();
    AddComponent<GunComponent>();

    GetComponent<SpriteComponent>()->Init(ResourceManager::m_textures[2], Settings::PlayerPosition, Settings::PlayerLayerDepth);
    GetComponent<VelocityComponent>()->Init(Settings::PlayerVelocity, Settings::PlayerSpeed);
    GetComponent<InputComponent>()->Init();
    GetComponent<FaceCursorComponent>()->Init();
    GetComponent<GunComponent>()->Init(0.5f);
    
    SpriteComponentPtr p_spriteComp = GetComponent<SpriteComponent>();
    sf::Vector2u textureSize = p_spriteComp->m_sprite.getTexture()->getSize();
    p_spriteComp->m_sprite.setOrigin(textureSize.x / 2, textureSize.x / 2);
}
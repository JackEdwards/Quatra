#include "Player.hpp"

Player::Player()
{
    AddComponent<SpriteComponent>();
    AddComponent<VelocityComponent>();
    AddComponent<InputComponent>();
    AddComponent<FaceCursorComponent>();
    AddComponent<GunComponent>();

    GetComponent<SpriteComponent>()->Init(ResourceManager::m_textures[2], sf::Vector2f(100, 100), 1);
    GetComponent<VelocityComponent>()->Init(sf::Vector2f(0.0f, 0.0f), 1.0f);
    GetComponent<InputComponent>()->Init();
    GetComponent<FaceCursorComponent>()->Init();
    GetComponent<GunComponent>()->Init(0.5f);
    
    SpriteComponentPtr p_spriteComp = GetComponent<SpriteComponent>();
    sf::Vector2u textureSize = p_spriteComp->m_sprite.getTexture()->getSize();
    p_spriteComp->m_sprite.setOrigin(textureSize.x / 2, textureSize.x / 2);
}
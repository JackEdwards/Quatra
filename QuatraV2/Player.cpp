#include "Player.hpp"

Player::Player()
{
    AddComponent(std::make_shared<SpriteComponent>(ResourceManager::m_textures[2], sf::Vector2f(100, 100)));
    AddComponent(std::make_shared<VelocityComponent>(sf::Vector2f(0.0f, 0.0f), 1.0f));
    AddComponent(std::make_shared<InputComponent>());
    AddComponent(std::make_shared<FaceCursorComponent>());
    AddComponent(std::make_shared<GunComponent>(0.5f));
    
    SpriteComponentPtr p_spriteComp = std::static_pointer_cast<SpriteComponent>(GetComponent(ComponentType::Sprite));
    sf::Vector2u textureSize = p_spriteComp->m_sprite.getTexture()->getSize();
    p_spriteComp->m_sprite.setOrigin(textureSize.x / 2, textureSize.x / 2);
}
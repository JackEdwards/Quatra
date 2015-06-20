#include "FiringSystem.hpp"

FiringSystem::FiringSystem()
{
    m_lock = ComponentType::Gun | ComponentType::Input | ComponentType::Sprite;
}

void FiringSystem::Update(EntityPtrList& entities, sf::Time time)
{
    std::unique_ptr<Bullet> newBullet = nullptr;

    for (EntityPtr& p_entity : entities) {
        if (KeyFitsLock(p_entity->m_types)) {
            InputComponentPtr p_inputComp = p_entity->GetComponent<InputComponent>();
            SpriteComponentPtr p_spriteComp = p_entity->GetComponent<SpriteComponent>();
            GunComponentPtr p_gunComp = p_entity->GetComponent<GunComponent>();
            
            if (p_inputComp->m_fireKeyPressed && p_gunComp->m_reloadClock.getElapsedTime().asSeconds() >= p_gunComp->m_reloadLimit) {
                sf::Vector2f position = p_spriteComp->m_sprite.getPosition();
                float rotation = p_spriteComp->m_sprite.getRotation();
                sf::Vector2f velocity = DegreesToVector2f(rotation - 90);

                newBullet = std::make_unique<Bullet>(position, velocity, rotation);
                p_gunComp->m_reloadClock.restart();
            }
        }
    }
    
    if (newBullet != nullptr) {
        entities.push_back(std::move(newBullet));
    }
}
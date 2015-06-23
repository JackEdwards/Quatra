#include "FiringSystem.hpp"

FiringSystem::FiringSystem()
{
    m_lock = ComponentType::Gun | ComponentType::Input | ComponentType::Transform;
}

void FiringSystem::Update(EntityPtrList& entities, sf::Time time)
{
    std::unique_ptr<Bullet> newBullet = nullptr;

    for (EntityPtr& p_entity : entities) {
        if (KeyFitsLock(p_entity->m_types)) {
            InputComponentPtr p_input = p_entity->GetComponent<InputComponent>();
            TransformComponentPtr p_transform = p_entity->GetComponent<TransformComponent>();
            GunComponentPtr p_gun = p_entity->GetComponent<GunComponent>();
            
            if (p_input->m_fireKeyPressed && p_gun->m_reloadClock.getElapsedTime().asSeconds() >= p_gun->m_reloadLimit) {
                sf::Vector2f position = p_transform->m_position;
                float rotation = p_transform->m_rotation;
                sf::Vector2f velocity = DegreesToVector2f(rotation - 90);

                newBullet = std::make_unique<Bullet>(position, velocity, rotation);
                p_gun->m_reloadClock.restart();
            }
        }
    }
    
    if (newBullet != nullptr) {
        entities.push_back(std::move(newBullet));
    }
}
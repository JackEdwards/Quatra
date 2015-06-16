#include "FiringSystem.hpp"

FiringSystem::FiringSystem()
{
    m_lock = ComponentType::Gun | ComponentType::Input | ComponentType::Sprite;
}

void FiringSystem::Update(EntityPtrList& entities)
{
    EntityPtrList entityQueue;

    for (EntityPtr entity : entities) {
        if (KeyFitsLock(entity->m_types)) {
            InputComponentPtr p_input = std::dynamic_pointer_cast<InputComponent>(entity->GetComponent(ComponentType::Input));
            SpriteComponentPtr p_sprite = std::dynamic_pointer_cast<SpriteComponent>(entity->GetComponent(ComponentType::Sprite));
            
            if (p_input->m_fireKeyPressed) {
                sf::Vector2f position = p_sprite->m_sprite.getPosition();
                float rotation = p_sprite->m_sprite.getRotation() - 90;
                sf::Vector2f velocity = DegreesToVector2f(rotation);

                entityQueue.push_back(std::make_shared<Bullet>(position, velocity));
            }
        }
    }
    
    entities.insert(entities.end(), entityQueue.begin(), entityQueue.end());
}
#include "FiringSystem.hpp"

FiringSystem::FiringSystem()
{
    m_lock = ComponentType::Gun | ComponentType::Input | ComponentType::Sprite;
}

void FiringSystem::Update(EntityPtrList& entities)
{
    EntityPtrList entityQueue;

    for (EntityPtr& entity : entities) {
        if (KeyFitsLock(entity->m_types)) {
            InputComponentPtr p_input = std::static_pointer_cast<InputComponent>(entity->GetComponent(ComponentType::Input));
            SpriteComponentPtr p_sprite = std::static_pointer_cast<SpriteComponent>(entity->GetComponent(ComponentType::Sprite));
            
            if (p_input->m_fireKeyPressed) {
                sf::Vector2f position = p_sprite->m_sprite.getPosition();
                float rotation = p_sprite->m_sprite.getRotation();
                sf::Vector2f velocity = DegreesToVector2f(rotation - 90);

                entityQueue.push_back(std::make_unique<Bullet>(position, velocity * 1.0f, rotation));
            }
        }
    }
    
    entities.insert(
        entities.end(),
        std::make_move_iterator(entityQueue.begin()),
        std::make_move_iterator(entityQueue.end())
    );
}
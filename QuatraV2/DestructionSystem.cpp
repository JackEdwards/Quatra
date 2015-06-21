#include "DestructionSystem.hpp"

DestructionSystem::DestructionSystem()
{
    m_lock = ComponentType::Perishable | ComponentType::Sprite;
}

void DestructionSystem::Update(EntityPtrList& entities)
{
    for (auto it = entities.begin(); it != entities.end();) {
        if (KeyFitsLock((*it)->m_types)) {
            SpriteComponentPtr p_sprite = (*it)->GetComponent<SpriteComponent>();
            PerishableComponentPtr p_perishable = (*it)->GetComponent<PerishableComponent>();
            sf::Vector2f position = p_sprite->m_sprite.getPosition();
            bool shouldPerish = false;
            
            if (p_perishable->m_perishCondition == PerishCondition::OutOfBounds) {
                shouldPerish = position.x < 0 || position.x > 1920 || position.y < 0 || position.y > 1200;
            }
            else if (p_perishable->m_perishCondition == PerishCondition::NoHealth) {
                
            }

            if (shouldPerish) {
                it = entities.erase(it);
            } else ++it;
        } else ++it;
    }
}
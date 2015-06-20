#include "DestructionSystem.hpp"

DestructionSystem::DestructionSystem()
{
    m_lock = ComponentType::Perishable | ComponentType::Sprite;
}

void DestructionSystem::Update(EntityPtrList& entities)
{
    for (auto it = entities.begin(); it != entities.end();) {
        if (KeyFitsLock((*it)->m_types)) {
            SpriteComponentPtr p_spriteComp = std::static_pointer_cast<SpriteComponent>((*it)->GetComponent(ComponentType::Sprite));
            PerishableComponentPtr p_perishableComp = std::static_pointer_cast<PerishableComponent>((*it)->GetComponent(ComponentType::Perishable));
            sf::Vector2f position = p_spriteComp->m_sprite.getPosition();
            bool shouldPerish = false;
            
            if (p_perishableComp->m_perishCondition == PerishCondition::OutOfBounds) {
                shouldPerish = position.x < 0 || position.x > 1920 || position.y < 0 || position.y > 1200;
            }
            else if (p_perishableComp->m_perishCondition == PerishCondition::NoHealth) {
                
            }

            if (shouldPerish) {
                it = entities.erase(it);
            } else ++it;
        } else ++it;
    }
}
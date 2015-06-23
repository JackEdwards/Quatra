#include "DestructionSystem.hpp"

DestructionSystem::DestructionSystem()
{
    m_lock = ComponentType::Perishable | ComponentType::Transform;
}

void DestructionSystem::Update(EntityPtrList& entities)
{
    for (auto it = entities.begin(); it != entities.end();) {
        if (KeyFitsLock((*it)->m_types)) {
            TransformComponentPtr p_transform = (*it)->GetComponent<TransformComponent>();
            PerishableComponentPtr p_perishable = (*it)->GetComponent<PerishableComponent>();
            sf::Vector2f position = p_transform->m_position;
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
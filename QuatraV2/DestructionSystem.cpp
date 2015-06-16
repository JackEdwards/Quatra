#include "DestructionSystem.hpp"

DestructionSystem::DestructionSystem()
{
    m_lock = ComponentType::Perishable | ComponentType::Sprite;
}

void DestructionSystem::Update(EntityPtrList& entities)
{
    /*for (EntityPtr entity : entities) {
        if (KeyFitsLock(entity->m_types)) {
            SpriteComponentPtr p_sprite = std::dynamic_pointer_cast<SpriteComponent>(entity->GetComponent(ComponentType::Sprite));
            PerishableComponentPtr p_perishable = std::dynamic_pointer_cast<PerishableComponent>(entity->GetComponent(ComponentType::Perishable));
            sf::Vector2f position = p_sprite->m_sprite.getPosition();

            if (position.x < 0 || position.x > 1280 || position.y < 0 || position.y > 1280) {
                p_perishable->m_shouldPerish = true;
            }
        }
    }*/
    
    for (auto it = entities.begin(); it != entities.end();) {
        if (KeyFitsLock((*it)->m_types)) {
            SpriteComponentPtr p_sprite = std::dynamic_pointer_cast<SpriteComponent>((*it)->GetComponent(ComponentType::Sprite));
            sf::Vector2f position = p_sprite->m_sprite.getPosition();
            bool isOutOfBounds = position.x < 0 || position.x > 1280 || position.y < 0 || position.y > 1280;

            if (isOutOfBounds) {
                it = entities.erase(it);
                std::cout << "Bullet deleted!\n";
            }
            else {
                ++it;
            }
        }
        else {
            ++it;
        }
    }
}
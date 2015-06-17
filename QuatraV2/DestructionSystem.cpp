#include "DestructionSystem.hpp"

DestructionSystem::DestructionSystem()
{
    m_lock = ComponentType::Perishable | ComponentType::Sprite;
}

void DestructionSystem::Update(EntityPtrList& entities)
{
    for (auto it = entities.begin(); it != entities.end();) {
        if (KeyFitsLock((*it)->m_types)) {
            SpriteComponentPtr p_sprite = std::static_pointer_cast<SpriteComponent>((*it)->GetComponent(ComponentType::Sprite));
            sf::Vector2f position = p_sprite->m_sprite.getPosition();
            bool isOutOfBounds = position.x < 0 || position.x > 1280 || position.y < 0 || position.y > 1280;

            if (isOutOfBounds) {
                it = entities.erase(it);
            }
            else ++it;
        }
        else ++it;
    }
}
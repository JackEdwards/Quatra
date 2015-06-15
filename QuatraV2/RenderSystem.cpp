#include "RenderSystem.hpp"

RenderSystem::RenderSystem()
{
    m_lock = ComponentType::Sprite;
}

void RenderSystem::Update(EntityPtrList& entities, sf::RenderWindow& window)
{
    for (EntityPtr entity : entities) {
        if (KeyFitsLock(entity->m_types)) {
            SpriteComponentPtr p_sprite = std::dynamic_pointer_cast<SpriteComponent>(entity->GetComponent(ComponentType::Sprite));

            window.draw(p_sprite->m_sprite);
        }
    }
}
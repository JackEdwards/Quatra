#include "RenderSystem.hpp"

RenderSystem::RenderSystem()
{
    m_lock = ComponentType::Sprite;
}

void RenderSystem::Update(EntityPtrList& entities, sf::RenderWindow& window)
{
    for (EntityPtr& p_entity : entities) {
        if (KeyFitsLock(p_entity->m_types)) {
            SpriteComponentPtr p_spriteComp = std::static_pointer_cast<SpriteComponent>(p_entity->GetComponent(ComponentType::Sprite));

            window.draw(p_spriteComp->m_sprite);
        }
    }
    
    
}
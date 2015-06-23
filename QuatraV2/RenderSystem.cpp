#include "RenderSystem.hpp"

RenderSystem::RenderSystem()
{
    m_lock = ComponentType::Sprite;
}

void RenderSystem::Update(EntityPtrList& entities, SpriteBatch& spriteBatch)
{
    for (EntityPtr& p_entity : entities) {
        if (KeyFitsLock(p_entity->m_types)) {
            SpriteComponentPtr p_sprite = p_entity->GetComponent<SpriteComponent>();

            spriteBatch.Draw(p_sprite->m_sprite);
        }
    }
}
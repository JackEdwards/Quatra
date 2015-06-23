#include "RenderSystem.hpp"

RenderSystem::RenderSystem()
{
    m_lock = ComponentType::Transform | ComponentType::Texture;
}

void RenderSystem::Update(EntityPtrList& entities, SpriteBatch& spriteBatch)
{
    for (EntityPtr& p_entity : entities) {
        if (KeyFitsLock(p_entity->m_types)) {
            TransformComponentPtr p_transform = p_entity->GetComponent<TransformComponent>();
            TextureComponentPtr p_texture = p_entity->GetComponent<TextureComponent>();

            spriteBatch.Draw(p_transform->m_position, p_texture->m_sourceRect);
        }
    }
}
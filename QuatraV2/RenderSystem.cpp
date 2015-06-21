#include "RenderSystem.hpp"

RenderSystem::RenderSystem()
{
    m_lock = ComponentType::Sprite;
}

void RenderSystem::Update(EntityPtrList& entities, sf::RenderWindow& window)
{
    std::vector<std::vector<sf::Sprite>> sprites(SpriteComponent::MAX_DEPTH + 1);

    for (EntityPtr& p_entity : entities) {
        if (KeyFitsLock(p_entity->m_types)) {
            SpriteComponentPtr p_sprite = p_entity->GetComponent<SpriteComponent>();
            int depth = p_sprite->m_depth;
            sf::Sprite sprite = p_sprite->m_sprite;

            sprites.at(depth).push_back(sprite);
        }
    }
    
    for (std::vector<sf::Sprite> spriteList : sprites) {
        for (sf::Sprite sprite : spriteList) {
            window.draw(sprite);
        }
    }
}
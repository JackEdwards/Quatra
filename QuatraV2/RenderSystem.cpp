#include "RenderSystem.hpp"

RenderSystem::RenderSystem(sf::RenderWindow* window)
{
    _lock = ComponentType::Sprite;
    
    _window = window;
}

void RenderSystem::VUpdate(EntityPtrList entities)
{
    for (EntityPtr entity : entities) {
        if (KeyFitsLock(entity->_types)) {
            SpriteComponentPtr sprite = std::dynamic_pointer_cast<SpriteComponent>(entity->GetComponent(ComponentType::Sprite));

            _window->draw(sprite->_sprite);
        }
    }
}
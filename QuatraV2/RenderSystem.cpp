#include "RenderSystem.hpp"

RenderSystem::RenderSystem(sf::RenderWindow* window)
{
    _flags = ComponentFlag::Sprite;
    
    _window = window;
}

void RenderSystem::VUpdate(std::vector<Entity *> entities)
{
    for (Entity* entity : entities) {
        if ((entity->_flags & _flags) == _flags) {
            SpriteComponent* sprite = dynamic_cast<SpriteComponent*>(entity->_components[ComponentFlag::Sprite]);

            _window->draw(sprite->_sprite);
        }
    }
}
#include "RenderSystem.hpp"

RenderSystem::RenderSystem(sf::RenderWindow* window)
{
    _types = ComponentType::Sprite;
    
    _window = window;
}

void RenderSystem::VUpdate(std::vector<Entity *> entities)
{
    for (Entity* entity : entities) {
        if ((entity->_types & _types) == _types) {
            SpriteComponent* sprite = dynamic_cast<SpriteComponent*>(entity->GetComponent(ComponentType::Sprite));

            _window->draw(sprite->_sprite);
        }
    }
}
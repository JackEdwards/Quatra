#include "FaceCursorSystem.hpp"

FaceCursorSystem::FaceCursorSystem(sf::RenderWindow* window)
{
    _types = ComponentType::FaceCursor | ComponentType::Sprite;
    
    _window = window;
}

void FaceCursorSystem::VUpdate(std::vector<Entity*> entities)
{
    for (Entity* entity : entities) {
        if ((entity->_types & _types) == _types) {
            SpriteComponent* sprite = dynamic_cast<SpriteComponent*>(entity->GetComponent(ComponentType::Sprite));
            
            // Get distance between sprite and mouses
            int x = sprite->_sprite.getPosition().x - sf::Mouse::getPosition(*_window).x;
            int y = sprite->_sprite.getPosition().y - sf::Mouse::getPosition(*_window).y;
            sf::Vector2i distance = sf::Vector2i(x, y);
            
            // Calculates rotation angle in radians and converts to degrees
            int angle = atan2(distance.y, distance.x) * (180 / M_PI);
            
            // atan2 returns an angle between -180 and 180
            // This code converts it to an angle between 0 and 359
            if (angle < 0) {
                angle = 360 - (-angle);
            }
            
            // 90 is subtracted from the angle because the angle result of atan2
            // is relative to the negative X axis
            sprite->_sprite.setRotation(angle - 90);
        }
    }
}
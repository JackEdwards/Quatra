#include "FaceCursorSystem.hpp"

FaceCursorSystem::FaceCursorSystem()
{
    m_lock = ComponentType::FaceCursor | ComponentType::Sprite;
}

void FaceCursorSystem::Update(EntityPtrList& entities, sf::RenderWindow& window)
{
    for (EntityPtr& p_entity : entities) {
        if (KeyFitsLock(p_entity->m_types)) {
            SpriteComponentPtr p_spriteComp = std::static_pointer_cast<SpriteComponent>(p_entity->GetComponent(ComponentType::Sprite));
            
            // Get distance between sprite and mouses
            int x = p_spriteComp->m_sprite.getPosition().x - sf::Mouse::getPosition(window).x;
            int y = p_spriteComp->m_sprite.getPosition().y - sf::Mouse::getPosition(window).y;
            sf::Vector2f distance = sf::Vector2f(x, y);
            
            // Calculates rotation angle in radians and converts to degrees
            int angle = Vector2fToDegrees(distance);
            
            // atan2 returns an angle between -180 and 180
            // This code converts it to an angle between 0 and 359
            if (angle < 0) {
                angle = 360 - (-angle);
            }
            
            // 90 is subtracted from the angle because the angle result of atan2
            // is relative to the negative X axis
            p_spriteComp->m_sprite.setRotation(angle - 90);
        }
    }
}
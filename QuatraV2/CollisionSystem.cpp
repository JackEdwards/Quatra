#include "CollisionSystem.hpp"

CollisionSystem::CollisionSystem()
{
    m_lock = ComponentType::Sprite;
}

void CollisionSystem::Update(EntityPtrList& entities)
{
    for (int i = 0; i < entities.size() - 1; ++i) {
        for (int j = i + 1; j < entities.size(); ++j) {
            sf::Sprite& p_spriteA = entities[i]->GetComponent<SpriteComponent>()->m_sprite;
            sf::Sprite& p_spriteB = entities[j]->GetComponent<SpriteComponent>()->m_sprite;
            
            sf::FloatRect boundsA = p_spriteA.getGlobalBounds();
            sf::FloatRect boundsB = p_spriteB.getGlobalBounds();

            if (boundsA.intersects(boundsB)) {
                if (entities[i]->HasComponent<HealthComponent>() && entities[j]->HasComponent<ImpactDamageComponent>()) {
                    entities[i]->GetComponent<HealthComponent>()->m_health -= entities[j]->GetComponent<ImpactDamageComponent>()->m_damage;
                }
            }
        }
    }
}
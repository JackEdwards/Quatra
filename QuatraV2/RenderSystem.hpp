#ifndef RENDERSYSTEM_HPP
#define RENDERSYSTEM_HPP

#include "System.hpp"
#include "SpriteComponent.hpp"

class RenderSystem : public System
{
public:
    RenderSystem();
    void Update(EntityPtrList& entities, sf::RenderWindow& window);
};

#endif

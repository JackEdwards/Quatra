#ifndef FACECURSORSYSTEM_HPP
#define FACECURSORSYSTEM_HPP

#include "Math.hpp"
#include "System.hpp"
#include "SpriteComponent.hpp"

class FaceCursorSystem : public System
{
public:
    FaceCursorSystem();
    void Update(EntityPtrList& entities, sf::RenderWindow& window);
};

#endif

#ifndef FACECURSORSYSTEM_HPP
#define FACECURSORSYSTEM_HPP

#include <math.h>
#include "System.hpp"
#include "SpriteComponent.hpp"

class FaceCursorSystem : public System
{
private:
    sf::RenderWindow* _window;

public:
    FaceCursorSystem(sf::RenderWindow* window);
    virtual void VUpdate(std::vector<Entity*> entities);
};

#endif

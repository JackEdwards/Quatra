#ifndef RENDERSYSTEM_HPP
#define RENDERSYSTEM_HPP

#include "System.hpp"
#include "SpriteComponent.hpp"

class RenderSystem : public System
{
private:
    sf::RenderWindow* _window;
public:
    RenderSystem(sf::RenderWindow* window);
    virtual void VUpdate(std::vector<Entity*> entities) override;
};

#endif

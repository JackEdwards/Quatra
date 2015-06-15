#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "InputSystem.hpp"
#include "MovementSystem.hpp"
#include "FaceCursorSystem.hpp"
#include "PhysicsSystem.hpp"
#include "RenderSystem.hpp"


class Game
{
private:
    sf::RenderWindow m_window;
    sf::Clock m_clock;
    EntityPtrList m_entities;
    InputSystem m_input;
    MovementSystem m_movement;
    FaceCursorSystem m_faceCursor;
    PhysicsSystem m_physics;
    RenderSystem m_render;
    
    
public:
    Game();
    void Run();
private:
    void Update();
    void Render();
    void HandleEvents();
};

#endif

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
    sf::RenderWindow _window;
    sf::Clock _clock;
    std::vector<Entity*> _entities;
    InputSystem _input;
    MovementSystem _movement;
    FaceCursorSystem _faceCursor;
    PhysicsSystem _physics;
    RenderSystem _render;
    
    
public:
    Game();
    ~Game();
    void Run();
private:
    void Update();
    void Render();
    void HandleEvents();
};

#endif

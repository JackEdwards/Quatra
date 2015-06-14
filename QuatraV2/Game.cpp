#include "Game.hpp"

Game::Game()
: _window(sf::VideoMode(1280, 1280), "Quatra", sf::Style::Close),
  _render(&_window),
  _faceCursor(&_window)
{
    _entities.push_back(new Player());
    _entities.push_back(new Enemy(sf::Vector2f(100, 100)));
    _entities.push_back(new Enemy(sf::Vector2f(600, 500)));
    _entities.push_back(new Enemy(sf::Vector2f(500, 200)));
}

Game::~Game()
{
    for (int i = 0; i < _entities.size(); ++i) {
        delete _entities[i];
    }
}

void Game::Run()
{
    while (_window.isOpen()) {
        Update();
        Render();
    }
}

void Game::Update()
{
    HandleEvents();
    float deltaTime = _clock.restart().asMilliseconds();
    
    _input.VUpdate(_entities);
    _movement.VUpdate(_entities);
    _faceCursor.VUpdate(_entities);
    _physics.VUpdate(_entities);
}

void Game::Render()
{
    _window.clear(sf::Color::White);

    _render.VUpdate(_entities);

    _window.display();
}

void Game::HandleEvents()
{
    sf::Event event;
    
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            _window.close();
        }
    }
}
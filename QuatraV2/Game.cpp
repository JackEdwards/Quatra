#include "Game.hpp"

Game::Game()
: _window(sf::VideoMode(1280, 1280), "Quatra", sf::Style::Close),
  _render(&_window),
  _faceCursor(&_window)
{
    _entities.push_back(std::make_shared<Player>());
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
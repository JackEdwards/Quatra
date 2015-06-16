#include "Game.hpp"

Game::Game()
: m_window(sf::VideoMode(1280, 1280), "Quatra", sf::Style::Close)
{
    m_entities.push_back(std::make_shared<Player>());
}

void Game::Run()
{
    while (m_window.isOpen()) {
        Update();
        Render();
    }
}

void Game::Update()
{
    HandleEvents();
    float deltaTime = m_clock.restart().asMilliseconds();
    
    m_input.Update(m_entities);
    m_movement.Update(m_entities);
    m_faceCursor.Update(m_entities, m_window);
    m_firing.Update(m_entities);
    m_physics.Update(m_entities, deltaTime);
    m_destruction.Update(m_entities);
}

void Game::Render()
{
    m_window.clear(sf::Color::White);

    m_render.Update(m_entities, m_window);

    m_window.display();
}

void Game::HandleEvents()
{
    sf::Event event;
    
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_window.close();
        }
    }
}
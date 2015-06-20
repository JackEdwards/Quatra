#include "Game.hpp"

Game::Game()
: m_window(sf::VideoMode(1920, 1200), "Quatra", sf::Style::Close)
{
    ResourceManager::LoadResources();
    LoadMap();
    m_entities.push_back(std::make_unique<Player>());
    m_entities.push_back(std::make_unique<Enemy>(sf::Vector2f(500, 500)));
    m_window.setVerticalSyncEnabled(true);
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
    float deltaTime = m_deltaClock.restart().asMilliseconds();
    
    m_input.Update(m_entities);
    m_movement.Update(m_entities);
    m_faceCursor.Update(m_entities, m_window);
    m_firing.Update(m_entities, m_gameClock.getElapsedTime());
    m_collision.Update(m_entities);
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

void Game::LoadMap()
{
    const int MAP_WIDTH = 24;
    const int MAP_HEIGHT = 15;

    int map[MAP_HEIGHT][MAP_WIDTH] = {
        {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
        {6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4},
        {6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4},
        {6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4},
        {6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4},
        {6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4},
        {6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4},
        {6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4},
        {6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4},
        {6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4},
        {6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4},
        {6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4},
        {6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4},
        {6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4},
        {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5}
    };
    
    for (int i = 0; i < MAP_HEIGHT; ++i) {
        for (int j = 0; j < MAP_WIDTH; ++j) {
            m_entities.push_back(std::make_unique<Tile>(ResourceManager::m_textures[map[i][j]], sf::Vector2f(j * 80, i * 80)));
        }
    }
}
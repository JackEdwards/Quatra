#include "Game.hpp"

Game::Game()
: m_window(sf::VideoMode(Settings::WindowWidth, Settings::WindowHeight), "Quatra", sf::Style::Close)
{
    ResourceManager::LoadResources();
    m_entities.push_back(std::make_unique<Player>());
    m_entities.push_back(std::make_unique<Enemy>(sf::Vector2f(500, 500)));
    m_entities.push_back(std::make_unique<Enemy>(sf::Vector2f(500, 500)));
    m_entities.push_back(std::make_unique<Enemy>(sf::Vector2f(500, 500)));
    m_entities.push_back(std::make_unique<Enemy>(sf::Vector2f(500, 500)));
    LoadMap();
    m_window.setVerticalSyncEnabled(true);
    
    m_font.loadFromFile(resourcePath() + "sansation.ttf");
    m_text.setFont(m_font);
    m_text.setString("FPS:");
    m_text.setColor(sf::Color::Red);
    m_text.setPosition(20, 20);
    m_fps = 0.0f;
    m_text2.setFont(m_font);
    m_text2.setString("Health: ");
    m_text2.setColor(sf::Color::Red);
    m_text2.setPosition(20, 60);
}

void Game::Run()
{
    sf::Clock clock;
    float lastTime = 0.0f;

    while (m_window.isOpen()) {
        Update();
        Render();
        
        float currentTime = clock.restart().asSeconds();
        m_fps = 1.0f / currentTime;
        if (currentTime != lastTime) {
            m_text.setString("FPS: " + std::to_string(m_fps));
        }
        lastTime = currentTime;
        
        m_text2.setString("Health: " + std::to_string(m_entities[0]->GetComponent<HealthComponent>()->m_health));
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
    m_window.draw(m_text);
    m_window.draw(m_text2);

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
            m_entities.push_back(std::make_unique<Tile>(ResourceManager::m_textures[map[i][j]], sf::Vector2f(j * ResourceManager::TILE_WIDTH, i * ResourceManager::TILE_HEIGHT)));
        }
    }
}
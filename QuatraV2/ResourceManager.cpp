#include "ResourceManager.hpp"

sf::Texture ResourceManager::m_playerTexture = sf::Texture();
sf::Texture ResourceManager::m_enemyTexture = sf::Texture();
sf::Texture ResourceManager::m_bulletTexture = sf::Texture();

ResourceManager::ResourceManager()
{
    
}

void ResourceManager::LoadResources()
{
    ResourceManager::m_playerTexture.loadFromFile(resourcePath() + "player.png");
    ResourceManager::m_enemyTexture.loadFromFile(resourcePath() + "enemy.png");
    ResourceManager::m_bulletTexture.loadFromFile(resourcePath() + "bullet.png");
}
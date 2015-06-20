#include "ResourceManager.hpp"

sf::Texture ResourceManager::m_bulletTexture;
std::vector<sf::Texture> ResourceManager::m_textures(7);
sf::Texture ResourceManager::m_spriteSheet;

ResourceManager::ResourceManager()
{
    
}

void ResourceManager::LoadResources()
{
    ResourceManager::m_spriteSheet.loadFromFile(resourcePath() + "spritesheet.png");

    int tileCount = m_spriteSheet.getSize().x / TILE_WIDTH;
    for (int i = 0; i < tileCount; ++i) {
        ResourceManager::m_textures[i].loadFromFile(resourcePath() + "spritesheet.png", sf::IntRect(i * TILE_WIDTH, 0, TILE_WIDTH, TILE_HEIGHT));
    }
    
    ResourceManager::m_bulletTexture.loadFromFile(resourcePath() + "bullet.png");
}
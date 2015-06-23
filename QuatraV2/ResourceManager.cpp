#include "ResourceManager.hpp"

sf::Texture ResourceManager::Spritesheet;
sf::Texture ResourceManager::BulletTexture;
std::vector<sf::IntRect> ResourceManager::SourceRects(7);

void ResourceManager::LoadResources()
{
    ResourceManager::Spritesheet.loadFromFile(resourcePath() + "spritesheet.png");
    
    for (int i = 0; i < 7; ++i) {
        ResourceManager::SourceRects[i] = sf::IntRect(i * TILE_WIDTH, 0, TILE_WIDTH, TILE_HEIGHT);
    }
    
    ResourceManager::BulletTexture.loadFromFile(resourcePath() + "bullet.png");
}
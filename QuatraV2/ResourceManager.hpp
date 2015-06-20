#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include "ResourcePath.hpp"
#include <SFML/Graphics.hpp>

class ResourceManager
{
public:
    static sf::Texture m_bulletTexture;
    static std::vector<sf::Texture> m_textures;
    static sf::Texture m_spriteSheet;
private:
    static const int TILE_WIDTH = 80;
    static const int TILE_HEIGHT = 80;

public:
    ResourceManager();
    static void LoadResources();
};

#endif

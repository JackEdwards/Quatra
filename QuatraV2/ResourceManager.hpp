#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include "ResourcePath.hpp"
#include <SFML/Graphics.hpp>

class ResourceManager
{
public:
    static sf::Texture m_playerTexture;
    static sf::Texture m_enemyTexture;
    static sf::Texture m_bulletTexture;

public:
    ResourceManager();
    static void LoadResources();
};

#endif

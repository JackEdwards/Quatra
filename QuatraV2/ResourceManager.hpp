#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include "ResourcePath.hpp"
#include <SFML/Graphics.hpp>

enum SpriteType
{
    EnemySprite,
    GroundSprite,
    PlayerSprite,
    TopWallSprite,
    RightWallSprite,
    BottomWallSprite,
    LeftWallSprite
};

class ResourceManager
{
public:
    static sf::Texture Spritesheet;
    static sf::Texture BulletTexture;
    static std::vector<sf::IntRect> SourceRects;
    static const int TILE_WIDTH = 80;
    static const int TILE_HEIGHT = 80;

public:
    virtual ~ResourceManager() = 0;
    static void LoadResources();
};

inline ResourceManager::~ResourceManager() {};

#endif

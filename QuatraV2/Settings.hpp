#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"

class Settings
{
public:
    static int WindowWidth;
    static int WindowHeight;
    static sf::Vector2f PlayerPosition;
    static sf::Vector2f PlayerVelocity;
    static int PlayerLayerDepth;
    static float PlayerSpeed;
    static float PlayerReloadSpeed;
    static int PlayerHealth;
    static sf::Vector2f EnemyVelocity;
    static int EnemyLayerDepth;
    static float EnemySpeed;
    static int EnemyDamage;
    static int BulletLayerDepth;
    static float BulletSpeed;
    static int TileLayerDepth;

public:
    virtual ~Settings() = 0;
    static void LoadSettings();
};

inline Settings::~Settings() {};

#endif

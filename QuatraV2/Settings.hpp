#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <SFML/Graphics.hpp>
#include <unordered_map>
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

public:
    virtual ~Settings() = 0;
    static void LoadSettings();
};

inline Settings::~Settings() {};

#endif

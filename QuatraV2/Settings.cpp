#include "Settings.hpp"

int Settings::WindowWidth;
int Settings::WindowHeight;
sf::Vector2f Settings::PlayerPosition;
sf::Vector2f Settings::PlayerVelocity;
int Settings::PlayerLayerDepth;
float Settings::PlayerSpeed;

void Settings::LoadSettings()
{
    Settings::WindowWidth = 1920;
    Settings::WindowHeight = 1200;
    Settings::PlayerPosition = sf::Vector2f(100.0f, 100.0f);
    Settings::PlayerVelocity = sf::Vector2f(0.0f, 0.0f);
    Settings::PlayerLayerDepth = 1;
    Settings::PlayerSpeed = 1.0f;
}
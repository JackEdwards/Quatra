#include "Settings.hpp"

int Settings::WindowWidth;
int Settings::WindowHeight;
sf::Vector2f Settings::PlayerPosition;
sf::Vector2f Settings::PlayerVelocity;
int Settings::PlayerLayerDepth;
float Settings::PlayerSpeed;
float Settings::PlayerReloadSpeed;
int Settings::PlayerHealth;
sf::Vector2f Settings::EnemyVelocity;
int Settings::EnemyLayerDepth;
float Settings::EnemySpeed;
int Settings::EnemyDamage;
int Settings::BulletLayerDepth;
float Settings::BulletSpeed;
int Settings::TileLayerDepth;

void Settings::LoadSettings()
{
    Settings::WindowWidth = 1920;
    Settings::WindowHeight = 1200;

    Settings::PlayerPosition = sf::Vector2f(100.0f, 100.0f);
    Settings::PlayerVelocity = sf::Vector2f(0.0f, 0.0f);
    Settings::PlayerLayerDepth = 1;
    Settings::PlayerSpeed = 1.0f;
    Settings::PlayerReloadSpeed = 0.01f;
    Settings::PlayerHealth = 100;

    Settings::EnemyVelocity = sf::Vector2f(0.0f, 0.0f);
    Settings::EnemyLayerDepth = 2;
    Settings::EnemySpeed = 1.0f;
    Settings::EnemyDamage = 1;
    
    Settings::BulletLayerDepth = 1;
    Settings::BulletSpeed = 5.0f;
    
    Settings::TileLayerDepth = 0;
}
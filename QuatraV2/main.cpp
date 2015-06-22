#include "Game.hpp"
#include "Settings.hpp"

int main()
{
    Settings::LoadSettings();
    Game game;
    game.Run();
}
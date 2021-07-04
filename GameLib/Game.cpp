#include "Game.h"

Game::Game() = default;

void Game::run()
{
    create_players_dialog();
    while (!gameOver()) {
        round();
    }
    printResult();
}
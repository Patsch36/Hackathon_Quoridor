#include "QuoridorGame.h"

QuoridorGame::QuoridorGame() = default;

void QuoridorGame::run()
{
    configGame();
    while (!gameOver())
    {
        round();
    }
    printResult();
}
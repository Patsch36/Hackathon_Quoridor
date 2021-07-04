#include "QuoridorGame.h"

QuoridorGame::QuoridorGame() = default;

void QuoridorGame::run()
{
    while (!gameOver())
    {
        round();
    }
    printResult();
}
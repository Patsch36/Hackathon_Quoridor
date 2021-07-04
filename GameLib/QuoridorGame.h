#pragma once
#include "AbstractGame.h"
#include "AbstractPlayer.h"
#include <array>
#include <memory>

class QuoridorGame : AbstractGame
{
public:
    QuoridorGame();
    void run() override;

private:
    GameField m_field;
    std::array<std::unique_ptr<AbstractPlayer>, 2> m_players;
    void round() override;
    bool gameOver() override;
    void printResult() override;
};
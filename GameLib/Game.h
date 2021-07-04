#pragma once
#include "IGame.h"

class Game : IGame
{
public:
    Game() override;
    void run() override;

private:
    GameField m_field;
    Player[2] m_player;
    void create_players_dialog();
    void round() override;
    bool gameOver() override;
    void printResult() override;
};
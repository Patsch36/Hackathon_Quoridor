#pragma once
#include "GameField.h"
#include "Player.h"

class IGame
{
public:
    virtual Game() = 0;
    virtual void run() = 0;

private:
    virtual GameField m_field;
    virtual Player[2] m_player;
    // void create_players_dialog(); ???
    virtual void round() = 0;
    virtual bool gameOver() = 0;
    virtual void printResult() = 0;
};

#pragma once
#include "AbstractPlayer.h"
#include "GameField.h"
#include <array>
#include <memory>

class AbstractGame
{
public:
    virtual void run() = 0;
    virtual void printResult() = 0;

protected:
    virtual void round() = 0;
    virtual bool gameOver() = 0;

private:
    GameField m_field;
    std::array<std::unique_ptr<AbstractPlayer>, 2> m_player;
};

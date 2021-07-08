#pragma once
#include "AbstractPlayer.h"
#include "GameField.h"
#include <array>
#include <memory>

class AbstractGame
{
public:
    AbstractGame() = default;
    virtual ~AbstractGame() = default;
    virtual void configGame() = 0;
    virtual void run() = 0;
    virtual void printResult() const = 0;

protected:
    virtual void round() = 0;
    [[nodiscard]] virtual bool gameOver() const = 0;
};
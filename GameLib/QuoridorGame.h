#pragma once
#include "AbstractGame.h"
#include "AbstractPlayer.h"
#include <array>
#include <memory>

class QuoridorGame : AbstractGame
{
public:
    QuoridorGame(); // dialog for creating player and stuff.
    void run() override;

private:
    GameField m_field;
    std::shared_ptr<AbstractPlayer> m_player1;
    std::shared_ptr<AbstractPlayer> m_player2;
    FieldSize m_fieldSize;
    void round() override;
    [[nodiscard]] bool gameOver()const override;
    void printResult() const override;
    void configGame() override;
};
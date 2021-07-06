#pragma once
#include "AbstractPlayer.h"

class HumanPlayer : public AbstractPlayer
{
public:
    explicit HumanPlayer(const Position &startPos);
    //~HumanPlayer();
    void playerTurn() override;
};
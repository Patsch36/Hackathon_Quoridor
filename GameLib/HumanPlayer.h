#pragma once
#include "AbstractPlayer.h"

class HumanPlayer : AbstractPlayer
{
public:
    bool move() override;

private:
    bool BuildBarrier();
}
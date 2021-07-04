#pragma once
#include "IPlayer.h"

class Player : IPlayer
{
public:
    Player() override;
    bool move() override;

    // Position getPosition();

private:
    // Position m_position;
    // Barrier[BarrierCount] m_barrier;
    const int BarrierCount = 3 override;

    bool BuildBarrier();
}
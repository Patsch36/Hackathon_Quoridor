#pragma once
#include "Position.h"
#include "Barrier.h"

class IPlayer
{
public:
    virtual IPlayer() = 0;
    virtual bool move() = 0;

    virtual Position getPosition();

private:
    virtual Position m_position;
    virtual Barrier[BarrierCount] m_barrier;
    virtual const int BarrierCount = 0;

    virtual bool BuildBarrier(); 
};
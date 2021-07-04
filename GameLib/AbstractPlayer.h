#pragma once
#include "Barrier.h"
#include "Position.h"
#include <cstddef>
#include <vector>

class AbstractPlayer
{
public:
    AbstractPlayer();
    virtual ~AbstractPlayer() = 0;
    virtual bool move() = 0;

    Position getPosition();

protected:
    void setPosition(const Position &pos);
    void addBarrier(const Barrier &barrier);

private:
    Position m_position;
    std::vector<Barrier> m_barriers;
    int barrierCount = 3; //all players have 3 Barriers.
};

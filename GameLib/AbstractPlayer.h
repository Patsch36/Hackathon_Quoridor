#pragma once
#include "Barrier.h"
#include "Position.h"
#include "Direction.h"
#include <cstddef>
#include <vector>

class AbstractPlayer
{
public:
    AbstractPlayer(const Position& startPos);
    virtual ~AbstractPlayer() = 0;
    virtual void playerTurn() = 0; // Turn of player (console dialog or automatic for bot player)

    Position getPosition();

protected:
    void move(const Direction &direction);
    bool addBarrier(const Barrier &barrier); //returns false when no barriers available anymore


private:
    Position m_position;
    std::vector<Barrier> m_barriers;
    int barrierCount = 3; //all players have 3 Barriers.
};

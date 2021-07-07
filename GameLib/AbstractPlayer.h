#pragma once

#include "Barrier.h"
#include "ConsoleUtils.h"
#include "Direction.h"
#include "Position.h"
#include <cstddef>
#include <vector>


class AbstractPlayer
{
public:
    explicit AbstractPlayer(Coordinate startCoords, const std::vector<ConsoleUtils::Colors> &player_color);
    virtual ~AbstractPlayer() = 0;
    virtual void playerTurn() = 0; // Turn of player (console dialog or automatic for bot player)

    Coordinate getCoordinate();
    std::string toString();
    bool hasVerticalBarrier(Coordinate &coordinate);
    bool hasHorizontalBarrier(Coordinate &coordinate);

protected:
    bool fieldCheck(const Coordinate &coordinate);
    void move(const Direction &direction);
    bool addBarrier(const Barrier &barrier); // returns false when no barriers available anymore

private:
    Coordinate m_coordinate;
    std::vector<Barrier> m_barriers;
    std::string m_playerCharacter;
    int barrierCount = 3; // all players have 3 Barriers.
};

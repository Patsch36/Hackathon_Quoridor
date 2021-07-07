#pragma once

#include "Direction.h"
#include "Position.h"
#include <array>
#include <memory>
#include <tuple>

class GameField;

class Barrier
{
public:
    Barrier(const Coordinate &start, const Direction &direction,
            std::weak_ptr<GameField> gamefield); // throws if not possible
    std::tuple<Coordinate, Direction> getLine(); // get the Two edge points of the line (we assume the line will always be
                                                 // straight.)
    static bool canCreate(
        const Coordinate &start, const Direction &direction,
        const std::shared_ptr<GameField> &gamefield); // checks if a barrier can be created with the point and the direction
    // TODO(walkerp): add destructor
private:
    Coordinate m_start;
    Direction m_direction;
    std::weak_ptr<GameField> m_gamefield;
    static void removeEdge(const Coordinate &start, const Coordinate &end, const std::shared_ptr<GameField> &field);
    static void removeEdge(const Coordinate &start, const Direction &direction,
                             const std::shared_ptr<GameField> &gamefield);
};
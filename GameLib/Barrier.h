#pragma once
#include "Direction.h"
#include "Position.h"
#include <array>
#include <tuple>

class Barrier
{
public:
    Barrier(const Position &start, const Position &end); // this constructor will throw if the Barrier can't be created.
    Barrier(const Position &start, const Direction &direction);
    std::tuple<Position, Position> getLine(); // get the Two edge points of the line (we assume the line will always be
                                              // straight.)
    static bool canCreate(const Position &start,
                          const Position &end); // checks if a barrier can be created between these two points.
    static bool canCreate(const Position &start,
                          const Direction &direction); // checks if a barrier can be created with the point and the direction

private:
    Position m_start;
    Position m_end;
};
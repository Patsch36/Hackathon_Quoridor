#pragma once

#include "Direction.h"
#include "Position.h"
#include <array>
#include <tuple>

class Barrier
{
public:
    Barrier(const Coordinate &start, const Coordinate &end); // this constructor will throw if the Barrier can't be created.
    Barrier(const Coordinate &start, const Direction &direction);
    std::tuple<Coordinate, Coordinate> getLine(); // get the Two edge points of the line (we assume the line will always be
                                              // straight.)
    static bool canCreate(const Coordinate &start,
                          const Coordinate &end); // checks if a barrier can be created between these two points.
    static bool canCreate(const Coordinate &start,
                          const Direction &direction); // checks if a barrier can be created with the point and the direction

private:
    const Coordinate m_start;
    const Coordinate m_end;
};
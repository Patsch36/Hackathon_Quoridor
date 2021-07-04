#pragma once
#include "Position.h"
#include <array>
#include <tuple>

class Barrier
{
public:
    //? maybe make it possible to use one point and a orientation flag instead of two points.
    
    Barrier(const Position& start, const Position& end); // this constructor will throw if the Barrier can't be created.
    std::tuple<Position,Position> getLine(); // get the Two edge points of the line (we assume the line will always be straight.)
    static bool canCreate(const Position &start, const Position &end); // checks if a barrier can be created between these two points.

private:
    Position m_start;
    Position m_end;
};
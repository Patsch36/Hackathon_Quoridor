#include "Position.h"

#include "../Graph/Graph.h"

Position::Position(Coordinate const &coordinate, Combinatorics::Vertex &vertex)
    : Position(coordinate.x(), coordinate.y(), vertex)
{
}

Position::Position(int x, int y, Combinatorics::Vertex &vertex) : Coordinate(x, y), m_vertex(vertex)
{
}

Combinatorics::Vertex const &Position::getVertex() const
{
    return m_vertex;
}

Combinatorics::Vertex &Position::getVertex()
{
    return m_vertex;
}

std::string Position::toString() const
{
    // TODO you might want to adapt this method so that the field is not always empty
    // if a player is at this position an X should be put there (if possible colored.)

    return " ";
}

std::string Position::toStringPlayer() const
{
    // TODO you might want to adapt this method so that the field is not always empty
    // if a player is at this position an X should be put there (if possible colored.)
    //oder hier fkt zum rausfinden welcher player: nachteil hier müsste Game eingebunden werden
    //                                             vorteil brauchen nicht noch mehr fkt oder müssen hier parameter mitgeben
    return "X";
}

bool Position::operator==(const Position &other) const
{
    return Coordinate::operator==(other) && m_vertex.getId() == other.m_vertex.getId();
}

bool Position::operator==(const Coordinate & /*other*/) const
{
    return false;
}

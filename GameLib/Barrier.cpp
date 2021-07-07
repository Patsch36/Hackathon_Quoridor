#include "Barrier.h"
#include "GameField.h"
#include <stdexcept>
#include <utility>

Coordinate getNextCoordinate(const Coordinate &start, const Direction &direction)
{
    switch (direction)
    {
    case Direction::up:
        return start.getAboveCoordinate();
    case Direction::left:
        return start.getLeftCoordinate();
    case Direction::down:
        return start.getBelowCoordinate();
    case Direction::right:
        return start.getRightCoordinate();
    }
}

Coordinate getNextCoordinateRightAngle(const Coordinate &start, const Direction &direction)
{
    switch (direction)
    {
    case Direction::up:
        return start.getLeftCoordinate();
    case Direction::left:
        return start.getBelowCoordinate();
    case Direction::down:
        return start.getRightCoordinate();
    case Direction::right:
        return start.getAboveCoordinate();
    }
}

void Barrier::removeEdge(const Coordinate &start, const Direction &direction, const std::shared_ptr<GameField> &gamefield)
{

    auto start1 = getNextCoordinate(start, direction);
    auto end = getNextCoordinateRightAngle(start, direction);
    auto end1 = getNextCoordinate(end, direction);
    removeEdge(start, start1, gamefield);
    removeEdge(end, end1, gamefield);
}

void Barrier::removeEdge(const Coordinate &start, const Coordinate &end, const std::shared_ptr<GameField> &field)
{
    Combinatorics::Graph &graph = field->getGraph();
    auto vertex1 = field->getPosition(start).getVertex().getId();
    auto vertex2 = field->getPosition(end).getVertex().getId();
    graph.removeEdge(vertex1, vertex2);
}

Barrier::Barrier(const Coordinate &start, const Direction &direction, std::weak_ptr<GameField> gamefield)
    : m_start(start), m_direction(direction), m_gamefield(std::move(gamefield))
{
    auto field = m_gamefield.lock();
    if (!canCreate(start, direction, field))
    {
        throw std::runtime_error("Barrier can't be created!");
    }
    removeEdge(start, direction, field);
}

bool Barrier::canCreate(const Coordinate &start, const Direction &direction, const std::shared_ptr<GameField> &gamefield)
{
    auto next1 = getNextCoordinate(start, direction);
    auto next2 = getNextCoordinate(next1, direction);
    return (gamefield->edgeBetweenCoordinatesExists(start, next1)) &&
           (gamefield->edgeBetweenCoordinatesExists(next1, next2));
}
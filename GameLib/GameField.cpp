#include "GameField.h"
#include "../Graph/Algorithm/BreadthFirstSearch.h"
#include "Position.h"
#include "cassert"
#include <list>
#include <set>

using Combinatorics::Edge;
using Combinatorics::Graph;

static std::string const delimiter_x_open = "   ";
static std::string const delimiter_x_closed = "---";
static std::string const delimiter_x_barrier_check = "S";
static std::string const delimiter_y_open = " ";
static std::string const delimiter_y_closed = "|";
static std::string const delimiter_y_barrier_check = "~";

GameField::GameField()
{
    for (int x = 0; x < s_width; x++)
    {
        for (int y = 0; y < s_height; y++)
        {
            m_field[x][y] = std::make_unique<Position>(Coordinate(x, y), m_graph.addVertex());
            if (y != 0)
            {
                m_graph.addEdge(getPosition(Coordinate(x, y)).getVertex(),
                                getPosition(Coordinate(x, y).getBelowCoordinate()).getVertex());
            }
            if (x != 0)
            {
                m_graph.addEdge(getPosition(Coordinate(x, y)).getVertex(),
                                getPosition(Coordinate(x, y).getLeftCoordinate()).getVertex());
            }
        }
    }
}

GameField::~GameField() = default;


std::string GameField::toString() const
{
    std::string result;
    for (int y = 0; y < s_height; y++)
    {
        for (int x = 0; x < s_width; x++)
        {
            printDelimiter(result, Coordinate(x, y));
        }
        result.append("\n");
        for (int x = 0; x < s_width; x++)
        {
            printContent(result, Coordinate(x, y));
        }
        result.append("\n");
    }
    return result;
}

// Operator has to be declared outside the class
std::ostream &operator<<(std::ostream &os, const GameField &gf)
{
    std::string result = gf.toString();
    os << result;
    return os;
}

void GameField::printDelimiter(std::string &result, Coordinate const &coordinate) const
{
    if (coordinate.y() != 0)
    {
        if (m_graph.hasEdge(getPosition(coordinate).getVertex(), getPosition(coordinate.getBelowCoordinate()).getVertex()))
        {
            result.append(delimiter_y_open);
        }
        else
        {
            result.append(delimiter_y_closed);
        }
    }
    result.append(delimiter_x_open);
}

void GameField::printContent(std::string &result, Coordinate const &coordinate) const
{
    if (coordinate.x() != 0)
    {
        if (m_graph.hasEdge(getPosition(coordinate).getVertex(), getPosition(coordinate.getLeftCoordinate()).getVertex()))
        {
            result.append(delimiter_x_open);
        }
        else
        {
            result.append(delimiter_x_closed);
        }
    }
    result.append(getPosition(coordinate).toString());
}

const Position &GameField::getPosition(Coordinate const &coordinate) const
{
    return *m_field.at(coordinate.x()).at(coordinate.y());
}

Position &GameField::getPosition(Coordinate const &coordinate)
{
    return *m_field.at(coordinate.x()).at(coordinate.y());
}

Combinatorics::EdgeId GameField::getEdgeIdBetweenCoordinates(Coordinate const &a, Coordinate const &b) const
{
    return m_graph.findEdge(getPosition(a).getVertex(), getPosition(b).getVertex());
}

Combinatorics::Edge const &GameField::getEdgeBetweenCoordinates(Coordinate const &a, Coordinate const &b) const
{
    assert(edgeBetweenCoordinatesExists(a, b));
    return m_graph.getEdge(getEdgeIdBetweenCoordinates(a, b));
}

Combinatorics::Edge &GameField::getEdgeBetweenCoordinates(Coordinate const &a, Coordinate const &b)
{
    return const_cast<Combinatorics::Edge &>(static_cast<GameField const *>(this)->getEdgeBetweenCoordinates(a, b));
}

bool GameField::edgeBetweenCoordinatesExists(Coordinate const &a, Coordinate const &b) const
{
    return getEdgeIdBetweenCoordinates(a, b) != Graph::INVALID_EDGE_ID;
}

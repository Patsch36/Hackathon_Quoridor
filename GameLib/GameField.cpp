#include "GameField.h"
#include "../Graph/Algorithm/BreadthFirstSearch.h"
#include "Position.h"
#include "cassert"
#include <cstddef>
#include <list>
#include <set>
#include <stdexcept>
#include <utility>

using Combinatorics::Edge;
using Combinatorics::Graph;

// static std::string const delimiter_player = "X";
static std::string const delimiter_x_open = "   ";
static std::string const delimiter_x_closed = " | ";
static std::string const delimiter_x_barrier_check = " S ";
static std::string const delimiter_y_open = "   ";
static std::string const delimiter_y_closed = "---";
static std::string const delimiter_y_barrier_check = " ~ ";
constexpr char center_delimiter = '+';

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

void GameField::setPlayers(std::weak_ptr<AbstractPlayer> player1, std::weak_ptr<AbstractPlayer> player2)
{
    m_player1 = std::move(player1);
    m_player2 = std::move(player2);
}

FieldSize GameField::getSize() const 
{
    return {s_width,s_height};
}

GameField::~GameField() = default;

std::string GameField::toString() const
{
    std::string result;
    for (int y = 0; y < s_height; y++)
    {
        result += center_delimiter;
        for (int x = 0; x < s_width; x++)
        {
            printDelimiter(result, Coordinate(x, y));
        }
        result.append("\n");
        result.append("|");
        for (int x = 0; x < s_width; x++)
        {
            printContent(result, Coordinate(x, y));
        }
        result.append(delimiter_x_closed + "\n");
    }
    result += center_delimiter;
    for (int x = 0; x < s_width; x++)
    {
        result.append(delimiter_y_closed + center_delimiter);
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
    std::shared_ptr<AbstractPlayer> player1 = m_player1.lock();
    std::shared_ptr<AbstractPlayer> player2 = m_player2.lock();
    if (coordinate.y() != 0)
    {
        if (m_graph.hasEdge(getPosition(coordinate).getVertex(), getPosition(coordinate.getBelowCoordinate()).getVertex()))
        {
            // if (player1->hasBarrier(coordinate)) //Interrogate all Players Barriers
            //    result.append(delimiter_y_open);
            // else if(player2->hasBarrier(coordinate))
            //    result.append(delimiter_y_open);
          
            result.append(delimiter_y_open);
        }
        else
        {
            result.append(delimiter_y_closed);
        }
    }
    else
    {
        result.append(delimiter_y_closed);
    }
    result += center_delimiter;
}

// TODO(Sascha): die funktion ist zu lang, bitte kürzer machen und Hilfsfunktionen erstellen!
void GameField::printContent(std::string &result, Coordinate const &coordinate) const
{
    std::shared_ptr<AbstractPlayer> player1 = m_player1.lock();
    std::shared_ptr<AbstractPlayer> player2 = m_player2.lock();
    if (coordinate.x() != 0)
    {
        if (m_graph.hasEdge(getPosition(coordinate).getVertex(), getPosition(coordinate.getLeftCoordinate()).getVertex()))
        {
            // if (player1->hasVerticalBarrier(coordinate)) //Interrogate all Players Barriers
            //    result.append(delimiter_x_barrier_check);
            // else if(player2->hasVerticalBarrier(coordinate))
            //    result.append(delimiter_x_barrier_check);
            result.append(delimiter_x_open);
        }
        else
        {
            result.append(delimiter_x_closed);
        }
    }
    else
    {
        // append empty space in the beginning that the format does not shift
        result.append((delimiter_x_open.length() - 1) / 2, ' ');
    }

    if (m_player1.expired() || m_player2.expired())
    {
        throw std::runtime_error("the players can't be deleted before the gameField is deleted.");
        //? maybe use shared pointers instead of weak pointers? I'm not sure if this would be better.
    }

    if (player1->getCoordinate() == coordinate)
    {
        result.append(player1->toString());
    }
    else if (player2->getCoordinate() == coordinate)
    {
        result.append(player2->toString());
    }
    else
    {
        result.append(getPosition(coordinate).toString());
    }
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

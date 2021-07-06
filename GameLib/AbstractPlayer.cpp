#include "AbstractPlayer.h"
#include <exception>

AbstractPlayer::AbstractPlayer(Coordinate startCoords, const std::vector<ConsoleUtils::Colors> &player_color)
    : m_coordinate(std::move(startCoords))
{
    if (player_color.empty())
    {
        throw std::runtime_error("player has to be colored!");
    }
    m_playerCharacter = ConsoleUtils::colorString("X", player_color);
}

AbstractPlayer::~AbstractPlayer() = default; // selbst pure virtual destruktoren müssen definiert werden.

Coordinate AbstractPlayer::getCoordinate()
{
    return m_coordinate;
}

std::string AbstractPlayer::toString()
{
    return m_playerCharacter;
}

void AbstractPlayer::move(const Direction &direction)
{
    switch (direction)
    {
    case Direction::up:
        m_coordinate = m_coordinate.getAboveCoordinate();
        break;
    case Direction::down:
        m_coordinate = m_coordinate.getBelowCoordinate();
        break;
    case Direction::left:
        m_coordinate = m_coordinate.getLeftCoordinate();
        break;
    case Direction::right:
        m_coordinate = m_coordinate.getRightCoordinate();
        break;
    }
}

bool AbstractPlayer::addBarrier(const Barrier &barrier)
{
    /*// Position of Barrier has to be declarated in playerTurn??
    if (barrierCount > 0)
    {
        m_barriers[barrierCount] = barrier;
    }*/
    return false;
}
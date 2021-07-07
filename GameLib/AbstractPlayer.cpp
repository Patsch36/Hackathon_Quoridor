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

std::string AbstractPlayer::toString() const
{
    return m_playerCharacter;
}

bool AbstractPlayer::hasVerticalBarrier(Coordinate &coordinate)
{
    for (Barrier barrier : m_barriers)
    {

        // if (coordinate == barrier.getStartCoord())
        //{
        //    if (coordinate.x() == barrier.getEndCoord())
        //        return true;
        //}
    }
    return false;
}

//? THis Method with playerTurn in class Game
bool AbstractPlayer::fieldCheck(const Coordinate &coordinate)
{
    //GameFiled field;
    //field.checkMove(coordinate);
    if (coordinate.x() >= 0 && coordinate.y() >= 0 && coordinate.x() <= 8 && coordinate.y() <= 8)
    {
        //? Barrier check and other player check?? or better do the playerTurn in Game class ?

        // if we do it here we have to bring the coordinate off all barriers here. how? maybe only way with an static array
        // out of object?
        return true;
    }
    else
        return false;
}

void AbstractPlayer::move(const Direction &direction)
{
    //? if out of field restart move in playerTurn?
    switch (direction)
    {
    case Direction::down:
        if (fieldCheck(m_coordinate.getAboveCoordinate()))
            m_coordinate = m_coordinate.getAboveCoordinate();
        else
            throw std::runtime_error("Player can't move out of Field");
        return;
    case Direction::up:
        if (fieldCheck(m_coordinate.getBelowCoordinate()))
            m_coordinate = m_coordinate.getBelowCoordinate();
        else
            throw std::runtime_error("Player can't move out of Field");
        return;
    case Direction::left:
        if (fieldCheck(m_coordinate.getLeftCoordinate()))
            m_coordinate = m_coordinate.getLeftCoordinate();
        else
            throw std::runtime_error("Player can't move out of Field");
        return;
    case Direction::right:
        if (fieldCheck(m_coordinate.getRightCoordinate()))
            m_coordinate = m_coordinate.getRightCoordinate();
        else
            throw std::runtime_error("Player can't move out of Field");
        return;
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
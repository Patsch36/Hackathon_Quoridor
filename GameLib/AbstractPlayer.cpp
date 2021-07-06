#pragma once
#include "AbstractPlayer.h"
#include <exception>

AbstractPlayer::AbstractPlayer(const Position &startPos,const std::vector<ConsoleUtils::Colors>& player_color) : m_postion(startPos)
{
    if(player_color.size()<1){
        throw std::runtime_error("player has to be colored!");
    }
    m_playerCharacter = ConsoleUtils::colorString("X",player_color);
}

Position AbstractPlayer::getPosition()
{
    return m_position;
}

std::string AbstractPlayer::toString()
{
    return m_playerCharacter;
}

void AbstractPlayer::move(const Direction &direction)
{
    //switch (direction)
    //{
    //case up:
    //    m_postion = m_position.getAboveCoordinate();
    //    break;
    //case down:
    //    m_postion = m_position.getBelowCoordinate();
    //    break;
    //case left:
    //    m_postion = m_position.getLeftCoordinate();
    //    break;
    //case right:
    //    m_postion = m_position.getRightCoordinate();
    //    break;
    //}
}

bool AbstractPlayer::addBarrier(const Barrier &barrier)
{
    // Position of Barrier has to be declarated in playerTurn??
    //if (barrierCount > 0)
    //{
    //    m_barriers[barrierCount] = barrier;
    //}
}
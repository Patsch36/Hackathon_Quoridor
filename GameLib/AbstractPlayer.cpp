#pragma once
#include "AbstractPlayer.h"

AbstractPlayer::AbstractPlayer(const Position &startPos) : m_postion(startPos)
{
}

Position AbstractPlayer::getPosition()
{
    return m_position;
}

void AbstractPlayer::move(const Direction &direction)
{
    switch (direction)
    {
    case up:
        m_postion = m_position.getAboveCoordinate();
        break;
    case down:
        m_postion = m_position.getBelowCoordinate();
        break;
    case left:
        m_postion = m_position.getLeftCoordinate();
        break;
    case right:
        m_postion = m_position.getRightCoordinate();
        break;
    }
}

bool AbstractPlayer::addBarrier(const Barrier &barrier)
{
    // Position of Barrier has to be declarated in playerTurn??
    if (barrierCount > 0)
    {
        m_barriers[barrierCount] = barrier;
    }
}
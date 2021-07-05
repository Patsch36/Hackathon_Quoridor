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
    m_postion = m_position + direction;
}

bool AbstractPlayer::addBarrier(const Barrier &barrier)
{
    // Position of Barrier has to be declarated in playerTurn??
    if (barrierCount > 0)
    {
        m_barriers[barrierCount] = barrier;
    }
}
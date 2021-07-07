<<<<<<< HEAD
#pragma once
#include "GameRules.h"

=======
#include "GameRules.h"

GameRules::GameRules(std::shared_ptr<GameField> field) : _field(field)
{
}

ruleBreakes GameRules::checkGameBorders()
{
    if (std::abs(moveCoordinate.x()) < s_width && std::abs(moveCoordinate.y()) < s_height)
        return true;
    return false;



    //return ruleBreakes::OUTOFFIELD;
}

ruleBreakes GameRules::checkBarrier()
{
    return ruleBreakes::BARRIER;
}

ruleBreakes GameRules::checkPlayer()
{
    return ruleBreakes::PLAYER;
}

ruleBreakes GameRules::CheckMovement()
{
    if (checkGameBorders() == ruleBreakes::OUTOFFIELD)
        return ruleBreakes::OUTOFFIELD;
    if (checkBarrier() == ruleBreakes::BARRIER)
        return ruleBreakes::BARRIER;
    if (checkPlayer() == ruleBreakes::PLAYER)
        return ruleBreakes::PLAYER;

    return ruleBreakes::NONE;
}
>>>>>>> a6ea6b9718041824b469ca41e2e6a03328e45cc8

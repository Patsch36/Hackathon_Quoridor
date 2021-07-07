#include "GameRules.h"

GameRules::GameRules(std::shared_ptr<GameField> field) : _field(field)
{
}

ruleBreakes GameRules::checkGameBorders()
{
    return ruleBreakes::OUTOFFIELD;
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

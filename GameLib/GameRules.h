#pragma once

#include "GameField.h"
#include <memory>

enum class ruleBreakes {
    NONE,
    OUTOFFIELD,                 // Player wanted to move outside the field
    BARRIER,                    // Player wanted to move over a barrier
    PLAYER                      // Player wanted to move to another player
};

// ====================================================================================================================

class GameRules : GameField
{
private:
    static ruleBreakes checkGameBorders();
    static ruleBreakes checkBarrier();
    static ruleBreakes checkPlayer();

    std::shared_ptr<GameField> _field;

public:
    ruleBreakes CheckMovement();
    GameRules(std::shared_ptr<GameField> field);
    ~GameRules(){} = default;
};
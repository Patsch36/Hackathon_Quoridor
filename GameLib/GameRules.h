#pragma once
<<<<<<< HEAD
#include <memory>
#include "GameField.h"


class GameRules
{
public:
    GameRules(std::weak_ptr<GameField> field);

private:
    std::weak_ptr<GameField> m_filed;
=======

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
>>>>>>> a6ea6b9718041824b469ca41e2e6a03328e45cc8
};
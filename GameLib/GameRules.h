#pragma once
#include <memory>
#include "GameField.h"


class GameRules
{
public:
    GameRules(std::weak_ptr<GameField> field);

private:
    std::weak_ptr<GameField> m_filed;
};
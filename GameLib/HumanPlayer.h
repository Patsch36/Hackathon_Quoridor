#pragma once
#include "AbstractPlayer.h"

class HumanPlayer : public AbstractPlayer
{
public:
    explicit HumanPlayer(const Coordinate &startCoords, const std::vector<ConsoleUtils::Colors> &player_color);
    void playerTurn() override;
};
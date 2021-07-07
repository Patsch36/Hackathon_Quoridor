#pragma once
#include "AbstractPlayer.h"

class HumanPlayer : public AbstractPlayer
{
public:
    explicit HumanPlayer(const Coordinate &startCoords, const std::vector<ConsoleUtils::Colors> &player_color);
    void playerTurn() override;

    private:
    void printPlayerMenu();
    void printMoveMenu();
    void printBarrierMenu(int &posStar_x, int &posStar_y, int &posEnd_x, int &posEnd_y);
};
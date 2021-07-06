#include "HumanPlayer.h"
#pragma once
#include "HumanPlayer.h"
#include "ConsoleUtils.h"

HumanPlayer::HumanPlayer(const Position &startPos) : AbstractPlayer(const Position &startPos)
{
}

void HumanPlayer::playerTurn()
{

    int input = 0;
    printPlayerMenu();
    // einlesen
    switch (input)
    {
    case 0: 
        printMoveMenu();
        int input = ConsoleUtils::readInteger();
        Direction direction = input;// input to direction
        move(direction);
        break;
    case 1:
        printBarrierMenu();
        int posStart_x = ConsoleUtils::readInteger();
        int posStart_y = ConsoleUtils::readInteger();
        int posEnd_x = ConsoleUtils::readInteger();
        int posEnd_y = ConsoleUtils::readInteger();
        Position posStart(posStart_x, posStart_y);
        Position posEnd(posEnd_x, posEnd_y);
        Barrier barrier(posStart, posEnd);
        break;
    }
}
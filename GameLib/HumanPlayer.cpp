#pragma once
#include "HumanPlayer.h"

void HumanPlayer::playerTurn()
{
    int input = 0;
    printPlayerMenu();
    // einlesen
    switch (input)
    {
    case 0:
        printMoveMenu();
        Direction direction;
        // input
        // inout to direction
        move(direction);
        break;
    case 1:
        printBarrierMenu();
        // input
        Position posStart(/*input to pos*/) Barrier barrier(posStart, posEnd);
        break;
    }
}
#pragma once
#include <iostream>
#include "ConsoleUtils.h"
#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(const Coordinate &startCoords, const std::vector<ConsoleUtils::Colors> &player_color)
    : AbstractPlayer(startCoords, player_color)
{
}

void HumanPlayer::playerTurn()
{
    Direction direction;
    int input = 0;
    printPlayerMenu();
    int gameTrain = ConsoleUtils::readInteger();
    switch (gameTrain)
    {
    case 0:
        printMoveMenu();
        direction = (Direction)ConsoleUtils::readInteger();
        move(direction);
        return;
    case 1:
        int posStart_x = 0;
        int posStart_y = 0;
        int posEnd_x = 0;
        int posEnd_y = 0;
        printBarrierMenu(posStart_x, posStart_y, posEnd_x, posEnd_y);
        Coordinate posStart(posStart_x, posStart_y);
        Coordinate posEnd(posEnd_x, posEnd_y);
        //Barrier barrier(posStart, posEnd);
        return;
    }

}

void HumanPlayer::printPlayerMenu()
{
    std::cout << "\nChose your came train:\n"
              << "0) Move your player\n"
              << "1) Add barrier\n";
}

void HumanPlayer::printMoveMenu()
{
    std::cout << "Move your player:\n"
              << "0) Up\n"
              << "1) Down\n"
              << "2) Left\n"
              << "3) Right\n";
}

void HumanPlayer::printBarrierMenu(int &posStart_x, int &posStart_y, int &posEnd_x, int &posEnd_y)
{
    std::cout << "Add barrier in between:\n"
              << "First Coordinate X:";
    posStart_x = ConsoleUtils::readInteger();
    std::cout << "First Coordinate Y:";
    posStart_y = ConsoleUtils::readInteger();
    std::cout << "Second Coordinate Y:";
    posEnd_x = ConsoleUtils::readInteger();
    std::cout << "Second Coordinate Y:";
    posEnd_y = ConsoleUtils::readInteger();

}

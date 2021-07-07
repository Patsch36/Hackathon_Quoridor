#include "GameLib/AbstractPlayer.h"
#include "GameLib/ConsoleUtils.h"
#include "GameLib/GameField.h"
#include "GameLib/HumanPlayer.h"
#include "Graph/Graph.h"
#include "Graph/Vertex.h"
#include <iostream>
#include <memory>

int main()
{
    using Colors = ConsoleUtils::Colors;
    std::cout << ConsoleUtils::colorString("Good luck, have fun!\n",
                                           {Colors::FG_black, Colors::BG_yellow, Colors::X_underline});

    Coordinate Pos1(0, 4);
    Coordinate Pos2(8, 4);
    // HumanPlayer Player1(Pos);
    // HumanPlayer Player2(Pos);
    auto player1 = std::make_shared<HumanPlayer>(Pos1, std::vector<ConsoleUtils::Colors>{Colors::BG_yellow,Colors::FG_black});
    auto player2 = std::make_shared<HumanPlayer>(Pos2, std::vector<ConsoleUtils::Colors>{Colors::FG_yellow});

    GameField field(player1, player2);
    std::cout << field << std::endl;

    player1->playerTurn();

    std::cout << field << std::endl;

    player1->playerTurn();
    std::cout << field << std::endl;

    return 0;
}

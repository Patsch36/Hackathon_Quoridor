#include "GameLib/ConsoleUtils.h"
#include "GameLib/GameField.h"
#include "GameLib/HumanPlayer.h"
#include "GameLib/AbstractPlayer.h"
#include "Graph/Vertex.h"
#include "Graph/Graph.h"
#include <iostream>
#include <memory>

int main()
{
    using Colors = ConsoleUtils::Colors;
    std::cout << ConsoleUtils::colorString("Good luck, have fun!\n",
                                           {Colors::FG_black, Colors::BG_yellow, Colors::X_underline});
   
    Combinatorics::Graph graph;
    Combinatorics::Vertex vertex(1, graph);
    Position Pos(0, 5, vertex);
    AbstractPlayer *Player = new HumanPlayer(Pos);
    //HumanPlayer Player1(Pos);
    //HumanPlayer Player2(Pos);

    GameField field(std::make_shared<HumanPlayer>(Pos),std::make_shared<HumanPlayer>(Pos));
    std::cout << field << std::endl;
    //IGame *game = new Quoridor();
    //game->Confic();
    //game->run();
    //delete(game);
    return 0;
}
 
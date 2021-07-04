#include "GameLib/ConsoleUtils.h"
#include "GameLib/GameField.h"
#include <iostream>

int main()
{
    using Colors = ConsoleUtils::Colors;
    std::cout << ConsoleUtils::colorString("Good luck, have fun!\n",
                                           {Colors::FG_black, Colors::BG_yellow, Colors::X_underline});
    GameField field;
    std::cout << field << std::endl;
    //IGame *game = new Quoridor();
    //game->Confic();
    //game->run();
    //delete(game);
    return 0;
}
 
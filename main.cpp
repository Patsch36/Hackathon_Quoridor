#include "GameLib/AbstractGame.h"
#include "GameLib/QuoridorGame.h"
#include <iostream>
#include <memory>

int main()
{
    std::unique_ptr<QuoridorGame> game = std::make_unique<QuoridorGame>();
    game->run();
    return 0;
}

#pragma once

class Game
{
public:
    Game();
    void run();

private:
    void create_players_dialog();
    void round();
    bool gameOver();
    void printResult();
};
#include "QuoridorGame.h"
#include "AbstractPlayer.h"
#include "ConsoleUtils.h"
#include "GameField.h"
#include "HumanPlayer.h"
#include <queue>

using Colors = ConsoleUtils::Colors;

QuoridorGame::QuoridorGame() : m_fieldSize(m_field.getSize())
{
}

void QuoridorGame::run()
{
    configGame();
    while (!gameOver())
    {
        round();
    }
    printResult();
}

void QuoridorGame::configGame()
{

    std::cout << ConsoleUtils::colorString("Good luck, have fun!\n",
                                           {Colors::FG_black, Colors::BG_yellow, Colors::X_underline});

    Coordinate StartPos1(0, m_fieldSize.height / 2);
    Coordinate StartPos2(m_fieldSize.width - 1, m_fieldSize.height / 2);
    std::vector<ConsoleUtils::Colors> colorsPlayer1{Colors::BG_yellow, Colors::FG_black};
    std::vector<ConsoleUtils::Colors> colorsPlayer2{Colors::FG_yellow};

    m_player1 = std::make_shared<HumanPlayer>(StartPos1, colorsPlayer1);
    m_player2 = std::make_shared<HumanPlayer>(StartPos2, colorsPlayer2);

    m_field.setPlayers(m_player1, m_player2);
}

void QuoridorGame::round()
{
    {
        ConsoleUtils::clearConsole();
        std::cout << m_field << std::endl;
        std::cout << "player1's (" << m_player1->toString() << ") Turn\n";
        m_player1->playerTurn();
    }
    {
        ConsoleUtils::clearConsole();
        std::cout << m_field << std::endl;
        std::cout << "player2's (" << m_player2->toString() << ") Turn\n";
        m_player2->playerTurn();
    }
}

bool QuoridorGame::gameOver() const
{
    // TODO make this an extra function
    if (m_player1->getCoordinate().x() == m_fieldSize.width - 1)
    {
        return true;
    }
    // TODO make this an extra function
    if (m_player2->getCoordinate().x() == 0)
    {
        return true;
    }
    return false;
}

void QuoridorGame::printResult() const
{
    std::string output = "congratulations ";
    // TODO make this an extra function
    if (m_player1->getCoordinate().x() == m_fieldSize.width - 1)
    {
        output += "player1";
    }
    // TODO make this an extra function
    if (m_player2->getCoordinate().x() == 0)
    {
        output += "player2";
    }
    output += " won!\n";

    std::cout << ConsoleUtils::colorString(output, {Colors::FG_black, Colors::BG_yellow, Colors::X_underline});
}
add_library(GameLib
    STATIC
    ConsoleUtils.h
    ConsoleUtils.cpp
    GameField.h
    GameField.cpp
    Position.h
    Position.cpp
    Coordinate.h
    Coordinate.cpp
    AbstractGame.h
    AbstractPlayer.h
    AbstractPlayer.cpp
    HumanPlayer.h
    HumanPlayer.cpp
    Barrier.h
    Barrier.cpp
    Direction.h
    QuoridorGame.h
    QuoridorGame.cpp
    )


set_project_warnings(GameLib)
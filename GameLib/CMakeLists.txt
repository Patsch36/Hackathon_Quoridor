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
 "IGame.h" "IPlayer.h" "Barrier.h")

set_project_warnings(GameLib)
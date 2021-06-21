cmake_minimum_required(VERSION 3.15)
project(Hackathon)

add_subdirectory(extern/googletest)

add_subdirectory(Graph)
add_subdirectory(Logger)
add_subdirectory(GameLib)

add_executable(
    Hackathon
    main.cpp
)

target_link_libraries(Hackathon GameLib GraphLib LoggerLib)

cmake_minimum_required(VERSION 3.15)
project(Hackathon)
include(cmake/CompilerWarnings.cmake)

add_subdirectory(extern/googletest)

add_subdirectory(Graph)
add_subdirectory(Logger)
add_subdirectory(GameLib)

add_executable(
    Hackathon
    main.cpp
)
set_project_warnings(Hackathon)

target_link_libraries(Hackathon GameLib GraphLib LoggerLib)

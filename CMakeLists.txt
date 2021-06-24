cmake_minimum_required(VERSION 3.15)
project(Hackathon)

set(CMAKE_CXX_STANDARD 17)

# include compiler warnings for unified compiler warnings along all devs
include(cmake/CompilerWarnings.cmake)

# add gtest
add_subdirectory(extern/googletest)

# add all the subdirectories with the local libraries
add_subdirectory(Graph)
add_subdirectory(Logger)
add_subdirectory(GameLib)

add_executable(
    Hackathon
    main.cpp
)
set_project_warnings(Hackathon)

target_link_libraries(Hackathon PRIVATE GameLib GraphLib LoggerLib)

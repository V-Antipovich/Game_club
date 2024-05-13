cmake_minimum_required(VERSION 3.27)
project(game_club_yadro)

set(CMAKE_CXX_STANDARD 20)

add_library(source_lib STATIC ParserConsole.cpp ParserConsoleException.cpp
        ParserFile.cpp ParserFileError.cpp TimeStamp.cpp
        TableInterval.cpp Table.cpp Client.cpp
        ClientsBase.cpp GamerClubEnv.cpp Event.cpp)

add_executable(gamer_club
        main.cpp

)
target_link_libraries(gamer_club source_lib)
enable_testing()

add_subdirectory(test)

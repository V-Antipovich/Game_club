cmake_minimum_required(VERSION 3.27)
project(game_club_yadro)

set(CMAKE_CXX_STANDARD 20)
set(SOURCES main.cpp ParserConsole.cpp ParserConsoleException.cpp
        ParserFile.cpp ParserFileError.cpp TimeStamp.cpp
        TableInterval.cpp Table.cpp Client.cpp
        ClientsBase.cpp GamerClubEnv.cpp Event.cpp)

add_executable(gamer_club
        ${SOURCES}
)

enable_testing()

add_subdirectory(test)

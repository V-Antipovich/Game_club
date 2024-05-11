cmake_minimum_required(VERSION 3.27)
project(game_club_yadro)

set(CMAKE_CXX_STANDARD 20)

add_executable(gamer_club
        main.cpp
        ParserConsole.cpp
        ParserConsoleException.cpp
        ParserFile.cpp
        ParserFileError.cpp
        Events/BaseEvent.cpp
        Events/ClientCameEvent.cpp
        Events/ClientSatEvent.cpp
        Events/NameTableRequiredEvent.cpp
        Events/NameRequiredEvent.cpp
        Events/EventsFactory.cpp
        Events/ClientGoneEvent.cpp
        Events/ClientWaitingEvent.cpp
        Events/ErrorEvent.cpp
        TimeStamp.cpp)

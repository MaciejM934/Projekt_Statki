cmake_minimum_required(VERSION 3.19)
project(Statki)

set(CMAKE_CXX_STANDARD 14)

add_executable(Statki main.cpp Board.cpp Ship.cpp battlecruiser.cpp
        Destroyer.cpp Player.cpp Second_Board.cpp Ship_manager.cpp Game.cpp)
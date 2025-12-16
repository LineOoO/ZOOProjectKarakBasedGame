cmake_minimum_required(VERSION 3.10)
project(ZOOProjectKarakBasedGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(ZOOProjectKarakBasedGame
        Main.cpp
        Card.cpp
        Card.h
        Map.cpp
        Map.h
        Log.h
        Hero.cpp
        Item.cpp
        Enemy.cpp
        Game.cpp
        InputReader.cpp
        Renderer.cpp
)
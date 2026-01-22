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
        Hero.h
        Item.cpp
        Item.h
        ItemFactory.cpp
        ItemFactory.h
        Enemy.cpp
        Enemy.h
        EnemyFactory.cpp
        EnemyFactory.h
        Game.cpp
        Game.h
        InputReader.cpp
        InputReader.h
        Renderer.cpp
        Renderer.h
)
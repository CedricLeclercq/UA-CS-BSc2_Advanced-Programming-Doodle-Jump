cmake_minimum_required(VERSION 3.16.3)
project(AdvancedProgrammingDoodleJump)

set(CMAKE_CXX_STANDARD 14)

SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/Modules/")

FIND_PACKAGE(SFML 2 COMPONENTS system window graphics)

add_executable(DoodleJump
        src/main.cpp
        src/GameLogic/Game.cpp
        src/GameLogic/Game.h
        src/Utilities/Stopwatch.cpp
        src/Utilities/Stopwatch.h
        src/GameLogic/Camera.cpp
        src/GameLogic/Camera.h
        src/Utilities/Random.cpp
        src/Utilities/Random.h
        src/GameLogic/World.cpp
        src/GameLogic/World.h
        src/Entities/BGTile.cpp
        src/Entities/BGTile.h
        src/Entities/Bonus.cpp
        src/Entities/Bonus.h src/Entities/Player.cpp src/Entities/Player.h)

cmake_minimum_required(VERSION 3.20)
project(DoodleJump)

set(CMAKE_CXX_STANDARD 14)

add_executable(DoodleJump
        src/main.cpp src/Game.cpp src/Game.h src/Stopwatch.cpp src/Stopwatch.h src/Camera.cpp src/Camera.h src/Random.cpp src/Random.h src/World.cpp src/World.h src/BGTile.cpp src/BGTile.h src/Bonus.cpp src/Bonus.h)

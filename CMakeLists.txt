cmake_minimum_required(VERSION 3.16.3)
project(AdvancedProgrammingDoodleJump)

set(CMAKE_CXX_STANDARD 14)

SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/Modules/")

FIND_PACKAGE(SFML 2 COMPONENTS system window graphics)


SET(SRC
        src/main.cpp
        src/graphics/Game.cpp
        src/graphics/Game.h
        src/gameLogic/Camera.cpp
        src/gameLogic/Camera.h
        src/gameLogic/World.cpp
        src/gameLogic/World.h
        src/entities/background/BGTile.cpp
        src/entities/background/BGTile.h
        src/entities/Bonus.cpp
        src/entities/Bonus.h
        src/entities/Player.cpp
        src/entities/Player.h
        src/entities/Platform.cpp
        src/entities/Platform.h
        src/utilities/Utilities.h
        src/entities/Entity.h
        src/entities/Entity.cpp
        src/factories/AbstractFactory.h
        src/factories/ConcreteFactory.cpp
        src/factories/ConcreteFactory.h
        src/utilities/Utilities.cpp
        src/controllers/Controllers.h
        src/controllers/entityControllers/BGTileController.h
        src/controllers/entityControllers/BGTileController.cpp
        src/controllers/entityControllers/BonusController.h
        src/controllers/entityControllers/BonusController.cpp
        src/controllers/entityControllers/PlatformController.h
        src/controllers/entityControllers/PlatformController.cpp
        src/controllers/entityControllers/PlayerController.h
        src/controllers/entityControllers/PlayerController.cpp
        src/controllers/Controllers.h
        src/controllers/Controller.cpp
        )

INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})

ADD_EXECUTABLE(AdvancedProgrammingDoodleJump ${SRC})

TARGET_LINK_LIBRARIES(AdvancedProgrammingDoodleJump ${SFML_LIBRARIES})

INSTALL(TARGETS AdvancedProgrammingDoodleJump DESTINATION ${PROJECT_SOURCE_DIR}/bin)
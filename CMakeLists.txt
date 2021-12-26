cmake_minimum_required(VERSION 3.10.2)
project(AdvancedProgrammingDoodleJump)

set(CMAKE_CXX_STANDARD 14)

SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/Modules/")

FIND_PACKAGE(SFML 2 COMPONENTS system window graphics)

SET(LogicLibrary
        src/factories/AbstractFactory.h
        src/factories/ConcreteFactory.h
        src/factories/ConcreteFactory.cpp
        src/gameLogic/Camera.h
        src/gameLogic/Camera.cpp
        src/gameLogic/World.h
        src/gameLogic/World.cpp
        src/models/Entity.h
        src/models/Entity.cpp
        src/models/Entities.h
        src/models/entities/BGTile.cpp
        src/models/entities/BGTile.h
        src/models/entities/Bonus.cpp
        src/models/entities/Bonus.h
        src/models/entities/Player.cpp
        src/models/entities/Player.h
        src/models/entities/Platform.cpp
        src/models/entities/Platform.h
        src/utilities/Utilities.h
        src/utilities/Utilities.cpp
        src/logicMain.cpp)

SET(SRC
        src/main.cpp
        src/graphics/Game.cpp
        src/graphics/Game.h
        src/gameLogic/Camera.cpp
        src/gameLogic/Camera.h
        src/gameLogic/World.cpp
        src/gameLogic/World.h
        src/models/entities/BGTile.cpp
        src/models/entities/BGTile.h
        src/models/entities/Bonus.cpp
        src/models/entities/Bonus.h
        src/models/entities/Player.cpp
        src/models/entities/Player.h
        src/models/entities/Platform.cpp
        src/models/entities/Platform.h
        src/utilities/Utilities.h
        src/models/Entity.h
        src/models/Entity.cpp
        src/factories/AbstractFactory.h
        src/factories/ConcreteFactory.cpp
        src/factories/ConcreteFactory.h
        src/utilities/Utilities.cpp
        src/controllers/Controllers.h
        src/controllers/entityControllers/BGTileController.h
        src/controllers/entityControllers/BGTileController.cpp
        src/controllers/entityControllers/PlatformsController.h
        src/controllers/entityControllers/PlatformsController.cpp
        src/controllers/entityControllers/PlayerController.h
        src/controllers/entityControllers/PlayerController.cpp
        src/controllers/Controllers.h
        src/controllers/Controller.cpp
        src/models/Entities.h src/observers/Observer.cpp src/observers/Observer.h src/observers/entityObservers/PlayerObserver.cpp src/observers/entityObservers/PlayerObserver.h src/observers/Observers.h)

INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})

ADD_EXECUTABLE(AdvancedProgrammingDoodleJump ${SRC})
ADD_EXECUTABLE(AdvancedProgrammingDoodleJumpLogic ${LogicLibrary})

TARGET_LINK_LIBRARIES(AdvancedProgrammingDoodleJump ${SFML_LIBRARIES})

INSTALL(TARGETS AdvancedProgrammingDoodleJump DESTINATION ${PROJECT_SOURCE_DIR}/bin)
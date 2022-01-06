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
        src/logicMain.cpp
        src/controllers/WorldController.cpp
        src/controllers/WorldController.h
        src/gameLogic/Score.cpp
        src/gameLogic/Score.h
        src/observers/entityObservers/PlatformObserver.cpp
        src/observers/entityObservers/PlatformObserver.h
        src/observers/entityObservers/BGTileObserver.cpp
        src/observers/entityObservers/BGTileObserver.h
        src/observers/entityObservers/WorldObserver.cpp
        src/observers/entityObservers/WorldObserver.h
        src/observers/entityObservers/PlayerObserver.cpp
        src/observers/entityObservers/PlayerObserver.h
        src/observers/entityObservers/ScoreObserver.cpp
        src/observers/entityObservers/ScoreObserver.h
        src/observers/Observer.h
        src/observers/Observers.h
        )

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
        src/models/Entities.h
        src/observers/Observer.h
        src/observers/entityObservers/PlayerObserver.cpp
        src/observers/entityObservers/PlayerObserver.h
        src/observers/Observers.h
        src/observers/entityObservers/ScoreObserver.cpp
        src/observers/entityObservers/ScoreObserver.h
        src/views/Views.h
        src/views/PlayerView.cpp
        src/views/PlayerView.h
        src/views/PlatformView.cpp
        src/views/PlatformView.h
        src/views/View.h
        src/views/BGTileView.cpp
        src/views/BGTileView.h
        src/controllers/WorldController.cpp
        src/controllers/WorldController.h
        src/gameLogic/Score.cpp
        src/gameLogic/Score.h
        src/observers/entityObservers/PlatformObserver.cpp
        src/observers/entityObservers/PlatformObserver.h
        src/observers/entityObservers/BGTileObserver.cpp
        src/observers/entityObservers/BGTileObserver.h
        src/observers/entityObservers/WorldObserver.cpp
        src/observers/entityObservers/WorldObserver.h src/textureManagers/TextureManager.cpp src/textureManagers/TextureManager.h src/textureManagers/entityTexManagers/BGTileTexManager.cpp src/textureManagers/entityTexManagers/BGTileTexManager.h src/textureManagers/entityTexManagers/PlayerTexManager.cpp src/textureManagers/entityTexManagers/PlayerTexManager.h src/textureManagers/entityTexManagers/PlatformTexManager.cpp src/textureManagers/entityTexManagers/PlatformTexManager.h src/textureManagers/TextureManagers.h)

INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})
INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}/src")

ADD_EXECUTABLE(AdvancedProgrammingDoodleJump ${SRC})
ADD_EXECUTABLE(AdvancedProgrammingDoodleJumpLogic ${LogicLibrary})

TARGET_LINK_LIBRARIES(AdvancedProgrammingDoodleJump ${SFML_LIBRARIES})

INSTALL(TARGETS AdvancedProgrammingDoodleJump DESTINATION ${PROJECT_SOURCE_DIR}/bin)
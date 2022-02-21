cmake_minimum_required(VERSION 3.20)
project(Game)

set(CMAKE_CXX_STANDARD 20)

set(SFML_INCLUDE_DIR "/home/luc/Libraries/SFML-2.5.1/include")
set(SFML_LIBRARY_DIR "/home/luc/Libraries/SFML-2.5.1/lib")
set(SFML_DIR "/home/luc/Libraries/SFML-2.5.1/lib/cmake/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

add_executable(Game main.cpp GameManager/Singleton.h GameManager/WindowConnector.cpp GameManager/WindowConnector.h GameManager/ResourceManager.cpp GameManager/ResourceManager.h GameConfig.h Engine.cpp Engine.h Input.cpp Draw.cpp Update.cpp GameObject/Component/Animation.cpp GameObject/Component/Animation.h GameStateManager/GameStateBase.h GameStateManager/GameStateMachine.h GameStateManager/GameStateMachine.cpp GameStateManager/GameStateBase.cpp GameStateManager/GSIntro.cpp GameStateManager/GSIntro.h GameStateManager/GSMenu.cpp GameStateManager/GSMenu.h GameStateManager/GSPlay.cpp GameStateManager/GSPlay.h GameStateManager/GSEnd.cpp GameStateManager/GSEnd.h GameObject/GameButton.cpp GameObject/GameButton.h GameStateManager/GSSetting.cpp GameStateManager/GSSetting.h GameStateManager/GSAbout.cpp GameStateManager/GSAbout.h GameStateManager/GSHighScore.cpp GameStateManager/GSHighScore.h GameObject/Player/IPState.h GameObject/Player/IPlayer.h GameObject/Player/Player.cpp GameObject/Player/Player.h GameObject/Component/Hitbox.cpp GameObject/Component/Hitbox.h GameObject/Player/PSIdle.cpp GameObject/Player/PSIdle.h GameObject/Player/PSAttack.cpp GameObject/Player/PSAttack.h GameObject/Player/PSRun.cpp GameObject/Player/PSRun.h GameObject/Player/IPlayer.cpp GameObject/Player/PSBlock.cpp GameObject/Player/PSBlock.h GameObject/Skeleton/Skeleton.cpp GameObject/Skeleton/Skeleton.h GameObject/Collision/CollisionManager.cpp GameObject/Collision/CollisionManager.h GameObject/TileMap/Block.cpp GameObject/TileMap/Block.h GameObject/TileMap/MapManager.cpp GameObject/TileMap/MapManager.h GameObject/Player/PSDeath.cpp GameObject/Player/PSDeath.h GameManager/PlayerConnector.cpp GameManager/PlayerConnector.h GameObject/Skeleton/ISkeleton.cpp GameObject/Skeleton/ISkeleton.h GameObject/Skeleton/ISState.h GameObject/Skeleton/SAttack.cpp GameObject/Skeleton/SAttack.h GameObject/Skeleton/SIdle.cpp GameObject/Skeleton/SIdle.h GameObject/Skeleton/SRun.cpp GameObject/Skeleton/SRun.h GameObject/Skeleton/SDeath.cpp GameObject/Skeleton/SDeath.h GameObject/EnemyManager.cpp GameObject/EnemyManager.h GameObject/Goblin/IGoblin.cpp GameObject/Goblin/IGoblin.h GameObject/Goblin/IGState.h GameObject/Goblin/GRun.cpp GameObject/Goblin/GRun.h GameObject/Goblin/GIdle.cpp GameObject/Goblin/GIdle.h GameObject/Goblin/GDeath.cpp GameObject/Goblin/GDeath.h GameObject/Goblin/GAttack.cpp GameObject/Goblin/GAttack.h GameObject/Goblin/Goblin.cpp GameObject/Goblin/Goblin.h GameManager/MapConnector.cpp GameManager/MapConnector.h GameObject/Mushroom/IMState.h GameObject/Mushroom/IMushroom.cpp GameObject/Mushroom/IMushroom.h GameObject/Mushroom/MAttack.cpp GameObject/Mushroom/MAttack.h GameObject/Mushroom/MIdle.cpp GameObject/Mushroom/MIdle.h GameObject/Mushroom/MRun.cpp GameObject/Mushroom/MRun.h GameObject/Mushroom/Mushroom.cpp GameObject/Mushroom/Mushroom.h GameObject/Mushroom/MDeath.cpp GameObject/Mushroom/MDeath.h GameObject/FlyingEye/IFlyingEye.cpp GameObject/FlyingEye/IFlyingEye.h GameObject/FlyingEye/IFState.h GameObject/FlyingEye/FIdle.cpp GameObject/FlyingEye/FIdle.h GameObject/FlyingEye/FAttack.cpp GameObject/FlyingEye/FAttack.h GameObject/FlyingEye/FDeath.cpp GameObject/FlyingEye/FDeath.h GameObject/FlyingEye/FRun.cpp GameObject/FlyingEye/FRun.h GameObject/FlyingEye/FlyingEye.cpp GameObject/FlyingEye/FlyingEye.h GameObject/HUD.cpp GameObject/HUD.h GameManager/ScoreManager.cpp GameManager/ScoreManager.h)
target_link_libraries (Game sfml-graphics sfml-window sfml-system sfml-audio)
cmake_minimum_required(VERSION 3.14)
project(SpaceInvadersSFML)

set(CMAKE_CXX_STANDARD 14)

if(WIN32)
    set(SFML_STATIC_LIBRARIES TRUE)
    set(CMAKE_EXE_LINKER_FLAGS "-static")
endif()


find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)
set(SOURCE_FILES src/main.cpp src/Game.cpp src/Game.h src/Vector2.h src/Vector2.cpp src/GameObject.h src/GameObject.cpp src/Alien.h src/Spaceship.h src/Spaceship.cpp src/Alien.cpp src/GameOver.h src/GameOver.cpp
        src/Score.cpp
        src/Score.h
        src/AlienSpiral.cpp
        src/AlienSpiral.h
        src/AlienBullets.cpp
        src/AlienBullets.h)
add_executable(SpaceInvadersSFML ${SOURCE_FILES} src/Alien.h src/Spaceship.h src/Spaceship.cpp src/GameOver.h)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

target_link_libraries (SpaceInvadersSFML sfml-graphics sfml-window sfml-system sfml-network sfml-audio)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Data/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Data/)
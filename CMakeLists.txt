cmake_minimum_required(VERSION 3.5)

project(snake)

# find_package(Raylib 0.5.0 REQUIRED COMPONENTS filesystem system)

include(FetchContent)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
    GIT_TAG "master"
    GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(raylib)

set(SOURCES
  src/main.c
  src/player.c
  src/apple.c
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

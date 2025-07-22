cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
project(KARTGAME)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

add_subdirectory(vendor/glm EXCLUDE_FROM_ALL)
add_subdirectory(vendor/SDL EXCLUDE_FROM_ALL)
add_subdirectory(vendor/SDL_image EXCLUDE_FROM_ALL)

add_executable(${PROJECT_NAME} 
source/entity.cpp
    source/game.cpp
    source/texture_manager.cpp
    source/player.cpp
    source/input_manager.cpp
    source/main.cpp)

target_include_directories("${PROJECT_NAME}" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories("${PROJECT_NAME}" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/vendor/SDL/include")
target_include_directories("${PROJECT_NAME}" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/vendor/SDL_image/include")

target_link_libraries(${PROJECT_NAME} PRIVATE SDL3_image::SDL3_image SDL3::SDL3 glm)

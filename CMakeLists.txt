set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../bin")

cmake_minimum_required(VERSION 3.16)
project(ecu_recetas_cli)

file(GLOB_RECURSE SOURCE_FILES ./src/*.c)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE ./headers/)

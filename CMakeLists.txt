cmake_minimum_required(VERSION 3.28)
project(genesis CXX)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Disable Compiler Extensions
set(CMAKE_CXX_EXTENSIONS OFF)

# Export Compile Commands for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Dependencies
find_package(raylib REQUIRED)

# Our Project
add_executable(${PROJECT_NAME}
        src/main.cpp
        src/Application.cpp
        src/Renderer.cpp
        src/Random.cpp
        src/Level/Level.cpp
        src/Graphics/SpriteLoader.cpp
)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(${PROJECT_NAME} raylib)

# Web Configurations
if(${CMAKE_SYSTEM_NAME} STREQUAL "Emscripten")
    # Tell Emscripten to build an example.html file.
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")
endif()

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if(APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()

cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(LMM LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find the installed raylib package
find_package(raylib 3.0 REQUIRED)

# Collect all .c files in the LMM/src folder and its subdirectories
file(GLOB_RECURSE LMM_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/LMM/src/*.cpp"
)

# Add the LMM library
add_library(lmm STATIC ${LMM_SOURCES})

# Set the include directories for the LMM library
target_include_directories(lmm
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/LMM/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/LMM/include/LMM>
    PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}/LMM/include/LMM
        ${CMAKE_CURRENT_SOURCE_DIR}/LMM/include/physics
        ${CMAKE_CURRENT_SOURCE_DIR}/LMM/include/visuals
)

# Add the example executable
add_executable(exm examples/main.cpp)

# Link the example to the LMM library
target_link_libraries(exm lmm raylib)

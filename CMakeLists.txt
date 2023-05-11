cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(LMM LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find and import the required Qt modules
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Charts Gui)
include_directories(${Qt6Widgets_INCLUDE_DIRS})
add_definitions(${Qt6Widgets_DEFINITIONS})

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
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/LMM/include/LMM/physics>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/LMM/include/LMM/visuals>
    PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}/LMM/include/LMM
)

# Add the example executable and link to the LMM library and the required Qt modules
add_executable(exm examples/main.cpp)
target_link_libraries(exm lmm Qt6::Core Qt6::Widgets Qt6::Charts Qt6::Gui)

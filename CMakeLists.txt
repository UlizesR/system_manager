cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(LLM LANGUAGES C CXX)

# Set the C++ standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# Collect all .c files in the LLM/src folder and its subdirectories
file(GLOB_RECURSE LLM_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/LLM/src/*.c"
)

# Add the LLM library
add_library(llm STATIC ${LLM_SOURCES})

# Set the include directories for the LLM library
target_include_directories(llm
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/LLM/src>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/LLM/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/LLM/include/LLM>
    PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}/LLM/include/LLM
)


# Add the app executable
add_executable(app main.cpp)

# Link the app to the LLM library
target_link_libraries(app llm)

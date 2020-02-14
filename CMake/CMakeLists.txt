cmake_minimum_required(VERSION 3.0)
project(CGraph)

execute_process(COMMAND python3 "${CMAKE_CURRENT_SOURCE_DIR}/A/preparing.py")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(CGraph ${PROJECT_SOURCE_DIR}/C/main.cpp)

add_subdirectory(${PROJECT_SOURCE_DIR}/B)

target_link_libraries(CGraph CListGraph)


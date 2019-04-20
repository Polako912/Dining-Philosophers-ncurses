cmake_minimum_required(VERSION 3.13)
project(Projekt2)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS "-thread")

find_package(Threads REQUIRED)

set(SOURCES Main.cpp Philosopher.cpp Philosopher.h Fork.cpp Fork.h)
add_executable(Projekt2 ${SOURCES})

target_link_libraries (Projekt2 ${CMAKE_THREAD_LIBS_INIT})
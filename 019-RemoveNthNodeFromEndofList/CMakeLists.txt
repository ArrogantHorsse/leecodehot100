cmake_minimum_required(VERSION 3.5)
project(RemoveNthNodeFromEnd)

set(SOURCES
    src/main.cpp
)
include_directories(
    include
)

add_executable(RemoveNthNodeFromEnd ${SOURCES})
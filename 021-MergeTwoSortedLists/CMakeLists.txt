cmake_minimum_required(VERSION 3.5)
project(MergeTwoSortedLists)

include_directories(
    include
)

set(SOURCES
    src/main.cpp
)

add_executable(MergeTwoSortedLists ${SOURCES})
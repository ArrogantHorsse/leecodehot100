cmake_minimum_required(VERSION 3.5)

project(AndroidServer)

set(SOURCES
    src/androidserver.cpp
)

add_executable(AndroidServer ${SOURCES})

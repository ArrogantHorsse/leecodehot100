cmake_minimum_required(VERSION 3.5)

project(QNXServer)

set(SOURCES
    src/qnxserver.cpp
)

add_executable(QNXServer ${SOURCES})

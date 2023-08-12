cmake_minimum_required(VERSION 3.26)

project(occupy C)

set(CMAKE_C_STANDARD 17)

add_executable(occupy
        main.c
        src/log.c
)
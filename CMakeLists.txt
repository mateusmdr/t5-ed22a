cmake_minimum_required(VERSION 3.23)
project(t5_ed22a)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(main
        main.c
        lista.c
        tipos.c
        grafo.c
        edb.c
        pilha.c)

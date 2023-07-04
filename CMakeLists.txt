cmake_minimum_required(VERSION 3.20)

project(forel LANGUAGES C)

set(CMAKE_C_STANDARD 90)

add_executable(forel  src/main.c src/help.h src/help.c src/forel.h src/forel.c)

target_link_libraries(forel m)

install(TARGETS forel
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
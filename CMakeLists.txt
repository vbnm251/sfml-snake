cmake_minimum_required(VERSION 3.26)
project(snake)

set(CMAKE_CXX_STANDARD 20)
set(DEFAULT_LIB_PATH /usr/lib/x86_64-linux-gnu/)

find_package(SFML 2.5 COMPONENTS graphics audio)

find_library(X11_LIBRARY NAMES X11 PATHS ${DEFAULT_LIB_PATH})
find_library(XCB_LIBRARY NAMES xcb PATHS ${DEFAULT_LIB_PATH})

if (X11_LIBRARY)
    message(STATUS "Found X11 lib: ${X11_LIBRARY}")
else ()
    message(FATAL_ERROR "X11 Not found in ${DEFAULT_LIB_PATH}")
endif ()

if (XCB_LIBRARY)
    message(STATUS "Found xcb lib: ${XCB_LIBRARY}")
else ()
    message(FATAL_ERROR "xcb Not found in ${DEFAULT_LIB_PATH}")
endif ()

add_executable(
        ${PROJECT_NAME} main.cpp
        game/Snake.cpp
        game/Apple.cpp
        game/Apple.h
        game/Game.cpp
        game/Game.h
        game/Apple.cpp
)

target_link_libraries(${PROJECT_NAME}
        sfml-graphics
        sfml-audio
        ${X11_LIBRARY}
        ${XCB_LIBRARY}
)

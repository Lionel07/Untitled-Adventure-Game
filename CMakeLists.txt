cmake_minimum_required (VERSION 2.6)
project (Adventure)

file(GLOB SRCS_ALL
    "src/includes/*.h"
    "src/*.cpp"
)
find_package(PkgConfig REQUIRED)
find_package(SDL REQUIRED)

include(FindSDL)
include_directories(${SDL_INCLUDE_DIR})

add_executable(adventure ${SRCS_ALL})

target_link_libraries(adventure ${SDL_LIBRARY})
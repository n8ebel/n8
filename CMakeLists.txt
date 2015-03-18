#cmake_minimum_required(VERSION 2.8.4)
#project(n8Lib)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

# Setup sdl
#
FIND_LIBRARY(SDL2_LIBRARY SDL2)
FIND_LIBRARY(SDL2_IMAGE_LIBRARY SDL2_image)
FIND_LIBRARY(SDL2_MIXER_LIBRARY SDL2_mixer)
FIND_LIBRARY(SDL2_TTF_LIBRARY SDL2_ttf)

# Build n8 library
#
file(GLOB_RECURSE sources src/*.cpp)
add_library(n8Lib ${sources})


INCLUDE_DIRECTORIES(${SDL2_LIBRARY}/Headers ${SDL2_IMAGE_LIBRARY}/Headers ${SDL2_MIXER_LIBRARY}/Headers ${SDL2_TTF_LIBRARY}/Headers)

# links this lib with SDL2
#
SET(LIBS ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_MIXER_LIBRARY} ${SDL2_TTF_LIBRARY})
target_link_libraries(n8Lib ${LIBS})


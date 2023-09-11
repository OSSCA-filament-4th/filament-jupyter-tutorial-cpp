cmake_minimum_required(VERSION 3.10)

# project setting
project(xeus-cling-for-filament)

# dependencies
add_subdirectory("ext")

find_package(xproperty REQUIRED)
find_package(xwidgets REQUIRED)
find_package(xtl REQUIRED)

# make library
set(sources src/canvas.cpp)

add_library(jupyter-canvas SHARED ${sources})
target_link_libraries(jupyter-canvas PUBLIC xtl xwidgets)
target_compile_options(jupyter-canvas PUBLIC -Wnused-parameter -Wextra -Wreorder)
target_include_directories(jupyter-canvas PUBLIC json xproperty xwidgets)

install(TARGETS filament
        CONFIGURATIONS Debug
        RUNTIME DESTINATION Debug/bin)
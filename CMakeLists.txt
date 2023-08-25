cmake_minimum_required(VERSION 3.10)

project(xeus-cling-for-filament)

set(USE_STATIC_LIBCXX 0 CACHE INTERNAL "")
set(FILAMENT_SUPPORTS_VULKAN 0 CACHE INTERNAL "")
set(FILAMENT_SKIP_SAMPLES 1 CACHE INTERNAL "")
add_subdirectory(filament)

install(TARGETS filament
        CONFIGURATIONS Debug
        RUNTIME DESTINATION Debug/bin)
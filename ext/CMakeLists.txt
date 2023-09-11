# dependecies directory

# filament options
set(USE_STATIC_LIBCXX 0 CACHE INTERNAL "")
set(FILAMENT_SUPPORTS_VULKAN 0 CACHE INTERNAL "")
set(FILAMENT_SKIP_SAMPLES 1 CACHE INTERNAL "")

add_subdirectory(filament)

# xeus-cling options
find_package(xproperty REQUIRED)
find_package(xwidgets REQUIRED)
find_package(xtl REQUIRED)

set(xtl_REQUIRED_VERSION 0.7.0)

if(NOT TARGET xtl)
    find_package(xtl ${xtl_REQUIRED_VERSION} REQUIRED)
endif()
# add_subdirectory(xproperty)
# add_subdirectory(xwidgets)
# add_subdirectory(xeus-cling)

# json
add_subdirectory(json)
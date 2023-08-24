cmake_minimum_required(VERSION 3.10)

project(lib_converter)

# cmake options
set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/shared_lib)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# clang options
set(CMAKE_CXX_COMPILER "clang++-12")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -lc++abi")

# dependency
find_package(LLVM CONFIG REQUIRED)
find_package(Cling CONFIG REQUIRED)

# ======================================
# Make shared library
# ======================================

# pre-declare empty cpp file to make shared libray
file(WRITE ${CMAKE_BINARY_DIR}/empty.cpp "")

# file path
set(FILAMENT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/filament/lib/x86_64)

# List of static libraries (.a files) without the extension
set(STATIC_LIBS
    libbasis_transcoder
    libbackend
    libbluegl
    libbluevk
    libcamutils
    libcivetweb
    libdracodec
    libfilabridge
    libfilaflat
    libfilamat_lite
    libfilamat
    # libfilament
    libfilament-iblprefilter
    libfilameshio
    libgeometry
    libgltfio_core
    libgltfio
    libibl-lite
    libibl
    libimage
    libktxreader
    libmatdbg
    libmeshoptimizer
    libmikktspace
    libshaders
    libsmol-v
    libstb
    libuberarchive
    libuberzlib
    libutils
    # libviewer
    # libvkshaders
    # libzstd
)

function(make_shared lib)

    # set target import library

    # Start with an empty list

    # Iterate through the arguments and append each to the result_list
    list(POP_FRONT ARGV)

    set(target_link "")
    foreach(arg IN LISTS ARGV)
        list(APPEND target_link -l${arg})
    endforeach()

    # make tmp directy and run archive
    set(target_lib ${FILAMENT_DIR}/${lib})
    add_custom_target(${lib}_make_directory ALL
        COMMAND ${CMAKE_COMMAND} -E make_directory ${target_lib}
    )

    add_custom_target(${lib}_shared ALL
        WORKING_DIRECTORY ${target_lib}
        COMMAND ${CMAKE_AR} -x ${target_lib}.a 
    )

    if("${target_link}" STREQUAL "")
    # if(DEFINED target_link)
        message("${lib}")
        add_custom_target(${lib}_link ALL 
            COMMAND ${CMAKE_CXX_COMPILER} -shared -o ${lib}.so ${target_lib}/*.o
            -stdlib=libc++ -L${CMAKE_BINARY_DIR} -Wl,-rpath,${CMAKE_BINARY_DIR}
        )
    else()
        message("${lib} ${target_link}")
        add_custom_target(${lib}_link ALL 
                COMMAND ${CMAKE_CXX_COMPILER} -shared -o ${lib}.so ${target_lib}/*.o
                -stdlib=libc++ -L${CMAKE_BINARY_DIR} -Wl,-rpath,${CMAKE_BINARY_DIR}
                ${target_link}
            )
    endif()

    add_custom_target(${lib}_clean ALL
        COMMAND ${CMAKE_COMMAND} -E remove_directory ${target_lib}
    )   

endfunction()

find_package(Cling REQUIRED)

make_shared(libbluegl)
make_shared(libbluevk)
make_shared(libutils)
make_shared(libbackend bluevk bluegl)
make_shared(libfilament utils)

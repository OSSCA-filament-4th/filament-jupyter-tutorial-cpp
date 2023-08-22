cmake_minimum_required(VERSION 3.10)

project(lib_converter)

# cmake options
set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/shared_lib)

# clang options
set(CMAKE_CXX_COMPILER "clang++-12")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -lc++abi")

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
    libfilament
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
    libviewer
    libvkshaders
    libzstd
)

foreach(LIB ${STATIC_LIBS})

    # set target import library
    set(TARGET_LIB ${FILAMENT_DIR}/${LIB})

    # make tmp directy and run archive
    add_custom_target(${LIB}_make_directory ALL
        COMMAND ${CMAKE_COMMAND} -E make_directory ${TARGET_LIB}
    )
    add_custom_target(${LIB}_shared ALL
        WORKING_DIRECTORY ${TARGET_LIB}
        COMMAND ${CMAKE_AR} -x ${TARGET_LIB}.a 
    )
    add_custom_target(${LIB}_clean ALL
        COMMAND ${CMAKE_COMMAND} -E remove_directory ${TARGET_LIB}
    )

    # make shared library
    set(${TARGETS} ${TARGET_LIB}/*.o)
    add_library(${LIB} SHARED ${CMAKE_BINARY_DIR}/empty.cpp)
    target_compile_features(${LIB} PRIVATE cxx_std_17)
    target_link_libraries(${LIB} ${TARGETS})

endforeach()
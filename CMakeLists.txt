cmake_minimum_required(VERSION 3.15)
project(bosch_island_spatial CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(PLUGIN_SOURCES
    src/plugin.cpp
    src/connection.cpp
)

set(PLUGIN_INCLUDE_DIRS
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/sdk
)

function(add_plugin_variant target_name steamdeck)
    add_library(${target_name} SHARED ${PLUGIN_SOURCES})
    target_include_directories(${target_name} PRIVATE ${PLUGIN_INCLUDE_DIRS})
    set_target_properties(${target_name} PROPERTIES
        PREFIX ""
        OUTPUT_NAME "${target_name}"
        CXX_VISIBILITY_PRESET hidden
        VISIBILITY_INLINES_HIDDEN ON
    )
    target_compile_options(${target_name} PRIVATE -Wall -Wextra -Wno-unused-parameter)
    target_link_libraries(${target_name} PRIVATE pthread ${CMAKE_DL_LIBS})
    if(steamdeck)
        target_compile_definitions(${target_name} PRIVATE THEISLE_SPATIAL_STEAMDECK=1)
    endif()
endfunction()

add_plugin_variant(theisle_spatial           FALSE)
add_plugin_variant(theisle_spatial_steamdeck TRUE)

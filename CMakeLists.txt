cmake_minimum_required(VERSION 3.30)
project(StMFC)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(SOURCES
        src/main.cpp
        src/convert.cpp
        src/convert.hpp
        src/StMFC_GUI.cpp
        src/StMFC_GUI.hpp
        src/exceptions.hpp
)
if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    add_executable(StMFC ${SOURCES})
else (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    add_executable(StMFC WIN32 ${SOURCES})
endif (${CMAKE_BUILD_TYPE} STREQUAL "Debug")

set(BUILD_EXAMPLES OFF CACHE BOOL "")
set(BUILD_PROGRAMS OFF CACHE BOOL "")
set(BUILD_TESTING OFF CACHE BOOL "")
add_subdirectory(libsndfile)
target_link_libraries(StMFC PRIVATE sndfile)

find_package(wxWidgets)
target_link_libraries(StMFC PRIVATE wxWidgets::wxWidgets)
file(COPY resources/StMFC_interface.png DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
file(COPY resources/StMFC_logo.png DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

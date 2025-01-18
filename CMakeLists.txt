cmake_minimum_required(VERSION 3.30)
project(StMFC)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(StMFC WIN32 #COULD NOT WORK FOR OTHER OS
        src/main.cpp
        src/convert.cpp
        src/convert.hpp
        src/StMFC_GUI.cpp
        src/StMFC_GUI.hpp
        src/exceptions.hpp
)
set(BUILD_EXAMPLES OFF FORCE)
set(BUILD_PROGRAMS OFF FORCE)
add_subdirectory(libsndfile)
target_link_libraries(StMFC PRIVATE sndfile)

find_package(wxWidgets CONFIG REQUIRED)
target_link_libraries(StMFC PRIVATE wx::core wx::base)
file(COPY resources/StMFC_interface.png DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
file(COPY resources/StMFC_logo.png DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

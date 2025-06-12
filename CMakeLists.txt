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
set(VERSION "1.0.3")

if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    add_executable(StMFC ${SOURCES})
else (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    add_executable(StMFC WIN32 ${SOURCES})
endif (${CMAKE_BUILD_TYPE} STREQUAL "Debug")

if (${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    set_target_properties(StMFC PROPERTIES MACOSX_BUNDLE TRUE)
    set_target_properties(StMFC PROPERTIES
        MACOSX_BUNDLE_BUNDLE_NAME "StMFC"
        MACOSX_BUNDLE_GUI_IDENTIFIER "com.justfollowyourdreams.StMFC"
        MACOSX_BUNDLE_BUNDLE_VERSION ${VERSION}
        MACOSX_BUNDLE_ICON_FILE "StMFC_logo.icns"
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${VERSION}
    )

    file(COPY resources/StMFC_interface.png DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/StMFC.app/Contents/MacOS)
    file(COPY resources/StMFC_logo.png DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/StMFC.app/Contents/MacOS)
    file(COPY resources/StMFC_logo.icns DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/StMFC.app/Contents/Resources)
else(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    file(COPY resources/StMFC_interface.png DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
    file(COPY resources/StMFC_logo.png DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
endif(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")

set(BUILD_EXAMPLES OFF CACHE BOOL "")
set(BUILD_PROGRAMS OFF CACHE BOOL "")
set(BUILD_TESTING OFF CACHE BOOL "")
add_subdirectory(libsndfile)
target_link_libraries(StMFC PRIVATE sndfile)

find_package(wxWidgets)
target_link_libraries(StMFC PRIVATE wxWidgets::wxWidgets)

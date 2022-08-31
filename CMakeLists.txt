cmake_minimum_required(VERSION 3.23)

project(b2bAI VERSION 1.0)
set(CMAKE_CXX_STANDARD 14 CACHE STRING "C++ version selection")  # or 11, 14, 17, 20
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # optional, ensure standard is supported
set(CMAKE_CXX_EXTENSIONS OFF)  # optional, keep compiler extensions off
enable_testing()

# Find python
set(Python3_ROOT_DIR /opt/homebrew/Cellar/python@3.10/3.10.6_1)
set(Python3_ADDITIONAL_VERSIONS 3.10.6)
find_package (Python3 COMPONENTS Interpreter Development)

message(STATUS "Python3: " ${Python3_INCLUDE_DIRS})


# Find boost
find_package(Boost 1.79.0 REQUIRED COMPONENTS log unit_test_framework filesystem)
add_definitions(${Boost_DEFINITIONS})

message(STATUS "Boost: " ${Boost_INCLUDE_DIR})


# Build shared library
set(CMAKE_SHARED_LIBRARY_PREFIX "")
option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

add_subdirectory(lib/midi_generator)

message(STATUS "Midi generator: " ${CMAKE_CURRENT_BINARY_DIR}/vst/midi_generator/midi_generator.cpp)

# Build python package
if(NOT IS_DIRECTORY ${CMAKE_BINARY_DIR}/midi_generator)
    file(COPY midi_generator DESTINATION ${CMAKE_BINARY_DIR} PATTERN ".github" EXCLUDE)
    file(COPY scripts/build.sh DESTINATION ${CMAKE_BINARY_DIR}/scripts)
    file(COPY scripts/create_note.py DESTINATION ${CMAKE_BINARY_DIR}/scripts)

    find_program(BASH bash)

    exec_program(${BASH} ${CMAKE_BINARY_DIR}/scripts ARGS "build.sh" RETURN_VALUE PACKAGE_NOT_BUILT)

    if(PACKAGE_NOT_BUILT)
        message(FATAL_ERROR "Couldn't build package")
    endif()
endif()


#JUCE
add_subdirectory(lib/JUCE EXCLUDE_FROM_ALL)

juce_add_module(lib/foleys_gui_magic)

set_property(GLOBAL PROPERTY JUCE_COPY_PLUGIN_AFTER_BUILD TRUE)

option(JUCE_ENABLE_MODULE_SOURCE_GROUPS "Enable Module Source Groups" ON)
set_property(GLOBAL PROPERTY USE_FOLDERS YES)

# Company settings
set_directory_properties(PROPERTIES JUCE_COMPANY_COPYRIGHT "GNU GENERAL PUBLIC LICENSE Version 3")
set_directory_properties(PROPERTIES JUCE_COMPANY_NAME "brahman")
set_directory_properties(PROPERTIES JUCE_COMPANY_WEBSITE "https://github.com/speedypleath/b2bAI-VST")
set_directory_properties(PROPERTIES JUCE_COMPANY_EMAIL "gheorgheandrei13@gmail.com")

# Plugin
add_subdirectory(vst)


# Tests
add_subdirectory(tests)
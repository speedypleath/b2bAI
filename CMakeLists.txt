cmake_minimum_required(VERSION 3.23)

project(b2bAI VERSION 1.0)
set(CMAKE_CXX_STANDARD 11 CACHE STRING "C++ version selection")  # or 11, 14, 17, 20
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # optional, ensure standard is supported
set(CMAKE_CXX_EXTENSIONS OFF)  # optional, keep compiler extensions off
enable_testing()

if(WIN32)
    set(BOOST_ROOT "C:\\Boost")
endif()
# Find boost
find_package(Boost REQUIRED COMPONENTS filesystem log unit_test_framework)
add_definitions(${Boost_DEFINITIONS})

message(STATUS "Boost: " ${Boost_INCLUDE_DIR})


# Build python package
if(NOT EXISTS ${CMAKE_BINARY_DIR}/midi_generator)
    # Build shared library
    add_subdirectory(midi_generator)
    file(COPY midi_generator DESTINATION ${CMAKE_BINARY_DIR} PATTERN ".github .idea dist build .vs" EXCLUDE)
    if(WIN32)
        file(COPY scripts/build.bat DESTINATION ${CMAKE_BINARY_DIR}/scripts)
        find_program(CMD powershell)

        exec_program(${CMD} ARGS "scripts/build.bat" RETURN_VALUE PACKAGE_NOT_BUILT)
    else()
        file(COPY scripts/build.sh DESTINATION ${CMAKE_BINARY_DIR}/scripts)
        find_program(BASH bash)

        exec_program(${BASH} ${CMAKE_BINARY_DIR}/scripts ARGS "build.sh" RETURN_VALUE PACKAGE_NOT_BUILT)
    endif()
    if(PACKAGE_NOT_BUILT)
        message(STATUS "Couldn't build package")
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
set_directory_properties(PROPERTIES JUCE_COMPANY_NAME "Brahman")
set_directory_properties(PROPERTIES JUCE_COMPANY_WEBSITE "https://github.com/speedypleath/b2bAI-VST")
set_directory_properties(PROPERTIES JUCE_COMPANY_EMAIL "gheorgheandrei13@gmail.com")

# Plugin
add_subdirectory(vst)


# Tests
add_subdirectory(tests)
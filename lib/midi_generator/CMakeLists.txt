cmake_minimum_required(VERSION 3.23)
project(pybind_midi)

add_subdirectory(../../midi_generator/pybind11)
add_library(note SHARED pybind.cpp API.cpp)
target_include_directories(note PRIVATE ${Boost_INCLUDE_DIR})
target_link_libraries(note ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${Boost_LIBRARIES} pybind11::module pybind11::embed pybind11::lto)

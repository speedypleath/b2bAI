

add_executable(test_python test_python.cpp)
set_property(TARGET test_python PROPERTY CXX_STANDARD 11)
target_include_directories(test_python PRIVATE ${Boost_INCLUDE_DIR})
target_include_directories(test_python PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_definitions(test_python PRIVATE "BOOST_TEST_DYN_LINK=1")
target_link_libraries(test_python ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} pybind11::embed)
add_test(NAME test_python_creation COMMAND test_python)

add_executable(test_extract test_extract.cpp)
target_include_directories(test_extract PRIVATE ${Boost_INCLUDE_DIR})
target_include_directories(test_extract PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_definitions(test_extract PRIVATE "BOOST_TEST_DYN_LINK=1")
target_link_libraries(test_extract ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} pybind11::embed shared_library)
add_test(NAME test_extract_creation COMMAND test_extract)

add_executable(test_api test_api.cpp)
target_include_directories(test_api PRIVATE ${Boost_INCLUDE_DIR})
target_include_directories(test_api PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_definitions(test_api PRIVATE "BOOST_TEST_DYN_LINK=1")
target_link_libraries(test_api ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} pybind11::embed shared_library)
add_test(NAME test_api_creation COMMAND test_api)

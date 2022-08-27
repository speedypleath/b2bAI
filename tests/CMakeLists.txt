add_executable(test_note test_note.cpp)

find_library(NOTE_LIB midi_generator_ext.so PATHS ${CMAKE_BINARY_DIR}/lib/midi_generator/)
if(NOTE_LIB)
    message(STATUS "Found library: ${NOTE_LIB}")
    target_include_directories(test_note PRIVATE ${Boost_INCLUDE_DIR})
    target_include_directories(test_note PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
    target_compile_definitions(test_note PRIVATE "BOOST_TEST_DYN_LINK=1")
    target_link_libraries(test_note ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${Python3_LIBRARIES} Boost::python310 ${NOTE_LIB})
    add_test(NAME test_note_creation COMMAND test_note)

    find_package (Python3 COMPONENTS Interpreter Development)

    message(STATUS "Python3 lib: " ${Boost_PYTHON310})

    add_executable(test_python test_python.cpp)
    target_include_directories(test_python PRIVATE ${Boost_INCLUDE_DIR})
    target_include_directories(test_python PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
    target_compile_definitions(test_python PRIVATE "BOOST_TEST_DYN_LINK=1")
    target_link_libraries(test_python ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${Python3_LIBRARIES} Boost::python310)
    add_test(NAME test_python_creation COMMAND test_python)

    add_executable(test_extract test_extract.cpp)
    target_include_directories(test_extract PRIVATE ${Boost_INCLUDE_DIR})
    target_include_directories(test_extract PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
    target_compile_definitions(test_extract PRIVATE "BOOST_TEST_DYN_LINK=1")
    target_link_libraries(test_extract ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${Python3_LIBRARIES} Boost::python310 ${NOTE_LIB})
    add_test(NAME test_extract_creation COMMAND test_extract)

endif()
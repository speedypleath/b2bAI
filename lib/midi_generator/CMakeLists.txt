add_library(MidiGenerator build.cpp)

set_target_properties(MidiGenerator PROPERTIES PREFIX "")

message(STATUS "Boost include: " ${Boost_INCLUDE_DIR})

target_link_libraries(MidiGenerator LINK_PUBLIC
        ${Boost_LIBRARIES} ${Python3_LIBRARIES})



install(TARGETS MidiGenerator DESTINATION lib)
install(FILES note.h DESTINATION include)


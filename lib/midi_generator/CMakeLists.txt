add_library(midi_generator_ext SHARED build.cpp note.cpp API.cpp)

set_target_properties(midi_generator_ext PROPERTIES PREFIX "")

message(STATUS "Boost include: " ${Boost_INCLUDE_DIR})

target_link_libraries(midi_generator_ext LINK_PUBLIC
        ${Boost_LIBRARIES} ${Python3_LIBRARIES})

install(TARGETS midi_generator_ext DESTINATION vst)
install(FILES note.h API.H  DESTINATION vst)


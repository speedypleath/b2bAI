#pragma once
#include "note.h"
#include <list>

namespace midi_generator
{
    std::list<Note> generate();
    std::list<Note> mutate();
    std::list<Note> continue_sequence();
    void save_file(std::string filename, std::list<Note> notes);
    
    template<typename T>
    std::list<T> to_std_list(const boost::python::object& iterable);
}
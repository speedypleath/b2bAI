#pragma once
#include "note.h"
#include <python3.10/Python.h>
#include <boost/python.hpp>
#include <list>

namespace midi_generator
{
    std::list<Note> generate();
    std::list<Note> mutate();
    std::list<Note> continue_sequence();
    std::list<Note> combine();
    void save_file(std::string filename, std::list<Note> notes);
     
    template<typename T>
    std::list<T> to_std_list(const boost::python::object& iterable);
}
#include "API.h"

using namespace boost::python;
namespace mg = midi_generator;

template<typename T>
std::list<T> mg::to_std_list(const object& iterable) {
    return std::list<T>( stl_input_iterator<T>(iterable),
                             stl_input_iterator<T>( ) );
}

std::list<mg::Note> mg::generate() {
    Py_Initialize();
    object main_module = import("midi_generator.cli.commands");
    object main_namespace = main_module.attr("__dict__");
    object generate = main_namespace["generate"];
    std::list<midi_generator::Note> lst;
    try {
        object result = generate();
        list notes = extract<list>(result);
        lst = to_std_list<midi_generator::Note>(notes);
    } catch (error_already_set) {
        PyErr_Print();
        return std::list<mg::Note>();
    }
    return lst;
}

std::list<mg::Note> mg::mutate() {
    std::list<mg::Note> notes;
    return notes;
}

std::list<mg::Note> continue_sequence() {
    std::list<mg::Note> notes;
    return notes;
}

std::list<mg::Note> combine() {
    std::list<mg::Note> notes;
    return notes;
}

void mg::save_file(std::string filename, std::list<mg::Note> notes) {
    return;
}
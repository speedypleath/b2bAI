#include <python3.10/Python.h>
#include <boost/python.hpp>
#include <string>
#include <boost/test/included/unit_test.hpp>
#include <../lib/midi_generator/note.h>
using namespace boost::unit_test;
using namespace boost::python;

void test_extract_note() {
    Py_Initialize();
    object main_module = import("__main__");
    object main_namespace = main_module.attr("__dict__");
    object result = exec_file("../scripts/create_note.py", main_namespace, main_namespace);
    object note_obj = main_namespace["random_note"];
    try {
        midi_generator::Note note = extract<midi_generator::Note>(note_obj);
        BOOST_TEST(true);
    } catch (error_already_set) {
        PyErr_Print();
        BOOST_TEST(false);
    }
}



test_suite* init_unit_test_suite( int /*argc*/, char* /*argv*/[] )
{
    framework::master_test_suite().
        add(BOOST_TEST_CASE_NAME(&test_extract_note, "extract note"));
    return 0;
}

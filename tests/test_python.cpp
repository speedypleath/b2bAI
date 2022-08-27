#define BOOST_TEST_MODULE test_python

#include <boost/test/included/unit_test.hpp>
#include <boost/test/included/unit_test.hpp>
#include <boost/test/data/test_case.hpp>
#include <boost/test/data/monomorphic.hpp>
#include <python3.10/Python.h>
#include <boost/python.hpp>
#include <string>

using namespace boost::python;

BOOST_AUTO_TEST_CASE(hello_world) {
    Py_Initialize();
    object main_module = import("__main__");
    object main_namespace = main_module.attr("__dict__");
    object result = exec(
        "def greet():                   \n"
        "   return 'Hello from Python!' \n",
        main_namespace, main_namespace);

    object greet = main_namespace["greet"];
    std::string message = extract<std::string>(greet());
    BOOST_TEST(message == std::string("Hello from Python!"), boost::test_tools::per_element());
}

BOOST_AUTO_TEST_CASE(import_module) {
    object midi_generator = import("midi_generator.cli");
    object main_namespace = midi_generator.attr("__dict__");
    BOOST_TEST(midi_generator.is_none() == false);
}

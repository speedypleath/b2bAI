#include <python3.10/Python.h>
#include <boost/python.hpp>
#include <string>
#include <boost/test/included/unit_test.hpp>
#include <../lib/midi_generator/note.h>

using namespace boost::unit_test;
using namespace boost::python;

void test_hello_world() {
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

void test_import_module() {
    object midi_generator = import("midi_generator.cli");
    object main_namespace = midi_generator.attr("__dict__");
    BOOST_TEST(midi_generator.is_none() == false);
}

void test_import_module_and_call_function() {
    object midi_generator = import("midi_generator.cli");
    object main_namespace = midi_generator.attr("__dict__");
    object print_cli = main_namespace["print_cli"];
    print_cli();
    BOOST_TEST(true);
}

test_suite* init_unit_test_suite( int /*argc*/, char* /*argv*/[] )
{
    framework::master_test_suite().
        add(BOOST_TEST_CASE_NAME(&test_hello_world, "hello world"));
    framework::master_test_suite().
        add(BOOST_TEST_CASE_NAME(&test_import_module, "import module"));
    framework::master_test_suite().
        add(BOOST_TEST_CASE_NAME(&test_import_module_and_call_function, "call function in module"));
  return 0;
}

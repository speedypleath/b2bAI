#include <pybind11/pybind11.h>
#include <pybind11/embed.h>
#include <string>
#include <iostream>
#include <boost/test/included/unit_test.hpp>

namespace py = pybind11;
using namespace boost::unit_test;
using namespace py::literals;

void test_hello_world() {
    pybind11::scoped_interpreter guard{};

    auto locals = py::dict("name"_a="World");
    py::exec(R"(
        message = "Hello, {name}!".format(**locals())
    )", py::globals(), locals);

    auto message = locals["message"].cast<std::string>();

    BOOST_ASSERT(message == "Hello, World!");
}

void test_import_module() {
    try {
        pybind11::scoped_interpreter guard{};

        py::module_ sys = py::module_::import("midi_generator");

        BOOST_ASSERT(true);
    }
    catch (pybind11::error_already_set& error) {
        std::cout << error.what();

        BOOST_ASSERT(false);
    }
}

void test_import_module_and_call_function() {
    try {
        pybind11::scoped_interpreter guard{};

        py::module_ mg = py::module_::import("midi_generator.cli");
        
        mg.attr("print_cli")();
        BOOST_ASSERT(true);
    } catch (py::error_already_set &error) {
        std::cout << error.what();
        BOOST_ASSERT(false);
    }
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

#include <boost/test/included/unit_test.hpp>
#include "../lib/midi_generator/API.h"
#include "pybind11/embed.h"

using namespace boost::unit_test;

void test_generate() {
    pybind11::initialize_interpreter();
    auto notes = midi_generator::generate();
    BOOST_TEST(notes.size() > 0);
}

void test_mutate() {
    auto notes = midi_generator::generate();
    std::list<midi_generator::Note> mutated = midi_generator::mutate(notes);
    BOOST_TEST(mutated.size() > 0);
    pybind11::finalize_interpreter();
}

void test_continue() {

};

test_suite* init_unit_test_suite( int /*argc*/, char* /*argv*/[] )
{
    framework::master_test_suite().
        add(BOOST_TEST_CASE_NAME(&test_generate, "generate sequence"));
    framework::master_test_suite().
        add(BOOST_TEST_CASE_NAME(&test_mutate, "mutate sequence"));
    return nullptr;
}

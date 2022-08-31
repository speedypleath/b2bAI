#include <python3.10/Python.h>
#include <boost/python.hpp>
#include <string>
#include <boost/test/included/unit_test.hpp>
#include <../lib/midi_generator/API.h>


using namespace boost::unit_test;
using namespace boost::python;

void test_generate() {
    BOOST_TEST(midi_generator::generate().size() > 0);
}

void test_mutate() {
    std::list<midi_generator::Note> notes = midi_generator::generate();
    std::list<midi_generator::Note> mutated = midi_generator::mutate(notes);
    BOOST_TEST(mutated.size() > 0);
}

void test_continue() {

};

test_suite* init_unit_test_suite( int /*argc*/, char* /*argv*/[] )
{
    framework::master_test_suite().
        add(BOOST_TEST_CASE_NAME(&test_generate, "generate sequence"));
    framework::master_test_suite().
        add(BOOST_TEST_CASE_NAME(&test_mutate, "mutate sequence"));
    return 0;
}

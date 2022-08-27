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


test_suite* init_unit_test_suite( int /*argc*/, char* /*argv*/[] )
{
    framework::master_test_suite().
        add(BOOST_TEST_CASE_NAME(&test_generate, "generate sequence"));
    // framework::master_test_suite().
    //     add(BOOST_TEST_CASE_NAME(&text_embed_note, "embed note"));
    return 0;
}

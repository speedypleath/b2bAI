#include <boost/test/included/unit_test.hpp>
#include "API.h"
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
}

void test_continue() {
    auto notes = midi_generator::generate();
    std::list<midi_generator::Note> continued = midi_generator::continue_sequence(notes);
    BOOST_TEST(continued.size() > 0);
}

void test_combine() {
    std::list<std::list<midi_generator::Note>> sequences;
    for (int i = 0; i < 3; i++)
        sequences.emplace_back(midi_generator::generate());

    std::list<midi_generator::Note> combined = midi_generator::combine(sequences);
    BOOST_TEST(combined.size() > 0);
}

void test_write() {
    auto notes = midi_generator::generate();
    midi_generator::save_file(notes, "/Users/speedypleath/Documents/brahman/test.mid");
    pybind11::finalize_interpreter();
}

__attribute__((unused)) test_suite* init_unit_test_suite( int /*argc*/, char* /*argv*/[] )
{
    framework::master_test_suite().
        add(BOOST_TEST_CASE_NAME(&test_generate, "generate sequence"));
    framework::master_test_suite().
        add(BOOST_TEST_CASE_NAME(&test_mutate, "mutate sequence"));
    framework::master_test_suite().
            add(BOOST_TEST_CASE_NAME(&test_continue, "continue sequence"));
    framework::master_test_suite().
            add(BOOST_TEST_CASE_NAME(&test_combine, "combine sequences"));
    framework::master_test_suite().
            add(BOOST_TEST_CASE_NAME(&test_write, "write sequence in file"));

    return nullptr;
}

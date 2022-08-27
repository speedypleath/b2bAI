#include <python3.10/Python.h>
#include <boost/python.hpp>
#include <string>
#include <iostream>
#include <boost/test/included/unit_test.hpp>
#include <../lib/midi_generator/note.h>
using namespace boost::unit_test;
using namespace boost::python;

midi_generator::Note note, note2(1, 2, 3.0, 4.0);

void default_constructor() {
  BOOST_TEST(note.pitch == 0);
  BOOST_TEST(note.velocity == 0);
  BOOST_TEST(note.start == 0.0);
  BOOST_TEST(note.end == 0.0);
}

void constructor() {
  BOOST_TEST(note2.pitch == 1);
  BOOST_TEST(note2.velocity == 2);
  BOOST_TEST(note2.start == 3.0);
  BOOST_TEST(note2.end == 4.0);
}

void stream_operator() {
  std::stringstream ss;
  ss << note;
  BOOST_TEST(std::string("Note(0, 0, 0, 0)\n") == ss.str(), boost::test_tools::per_element());
}

void equality_operator() {
  midi_generator::Note note3 = midi_generator::Note();
  BOOST_TEST(note == note3);
}

void inequality_operator() {
  BOOST_TEST(note != note2);
}


test_suite* init_unit_test_suite( int /*argc*/, char* /*argv*/[] )
{
  framework::master_test_suite().
      add(BOOST_TEST_CASE_NAME(&default_constructor, "default constructor"));
  framework::master_test_suite().
      add(BOOST_TEST_CASE_NAME(&constructor, "constructor"));
  framework::master_test_suite().
      add(BOOST_TEST_CASE_NAME(&stream_operator, "stream operator"));
  framework::master_test_suite().
      add(BOOST_TEST_CASE_NAME(&equality_operator, "equality operator"));
  framework::master_test_suite().
      add(BOOST_TEST_CASE_NAME(&inequality_operator, "inequality operator"));

  return 0;
}

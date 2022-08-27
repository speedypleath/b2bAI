#define BOOST_TEST_MODULE test_note
#include <iostream>
#include <string>
#include <boost/test/included/unit_test.hpp>
#include <boost/test/included/unit_test.hpp>
#include <boost/test/data/test_case.hpp>
#include <boost/test/data/monomorphic.hpp>
#include <../lib/midi_generator/note.h>

namespace data = boost::unit_test::data;

midi_generator::Note note, note2(1, 2, 3.0, 4.0);

BOOST_AUTO_TEST_CASE(default_constructor) {
  BOOST_CHECK_EQUAL(note.pitch, 0);
  BOOST_CHECK_EQUAL(note.velocity, 0);
  BOOST_CHECK_EQUAL(note.start, 0.0);
  BOOST_CHECK_EQUAL(note.end, 0.0);
}

BOOST_AUTO_TEST_CASE(constructor) {
  BOOST_CHECK_EQUAL(note2.pitch, 1);
  BOOST_CHECK_EQUAL(note2.velocity, 2);
  BOOST_CHECK_EQUAL(note2.start, 3.0);
  BOOST_CHECK_EQUAL(note2.end, 4.0);
}

BOOST_AUTO_TEST_CASE(test_stream_output) {
  std::stringstream ss;
  ss << note;
  BOOST_TEST(std::string("Note(0, 0, 0, 0)\n") == ss.str(), boost::test_tools::per_element());
}

BOOST_DATA_TEST_CASE(test_equality, data::make(note), var) {
  BOOST_CHECK_EQUAL(var, note);
}

BOOST_DATA_TEST_CASE(test_inequality, data::make(note), var) {
  BOOST_CHECK_NE(var, note2);
}
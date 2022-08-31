#include <pybind11/pybind11.h>
#include <pybind11/embed.h>
#include <boost/test/included/unit_test.hpp>
#include "../lib/midi_generator/note.h"

namespace py = pybind11;
using namespace boost::unit_test;
using namespace py::literals;

void test_extract_note() {
    pybind11::scoped_interpreter guard{};

    auto locals = py::dict();
    py::exec(R"(
        from note import Note
        test_note = Note(60, 100, 0, 2)
    )", py::globals(), locals);

    try {
        auto src = locals["test_note"];
        midi_generator::Note note;
        note.pitch =  src.attr("pitch").cast<int>();
        note.velocity = src.attr("velocity").cast<int>();
        note.start = src.attr("start").cast<double>();
        note.end = src.attr("end").cast<double>();
        BOOST_TEST(note.pitch == 60);
        BOOST_TEST(note.velocity == 100);
        BOOST_TEST(note.start == 0.0f);
        BOOST_TEST(note.end == 2.0f);
    } catch (py::error_already_set &error) {
        BOOST_TEST(false);
    }
}

void text_embed_note() {
    pybind11::scoped_interpreter guard{};

    py::module_ module = py::module_::import("note");

    auto constructor = module.attr("Note")(60, 100, 0.0f, 2.0f);
    auto locals = py::dict();

    py::exec(R"(
        from note import Note

        def check_note(note: Note):
            if note.pitch == 60 and note.velocity == 100:
                return True
            return False
    )", py::globals(), locals);
    auto check = locals["check_note"];
    auto src = check(constructor);
    BOOST_TEST(src.cast<bool>());
}



test_suite* init_unit_test_suite( int /*argc*/, char* /*argv*/[] )
{
    framework::master_test_suite().
        add(BOOST_TEST_CASE_NAME(&test_extract_note, "extract note"));
    framework::master_test_suite().
        add(BOOST_TEST_CASE_NAME(&text_embed_note, "embed note"));
    return nullptr;
}

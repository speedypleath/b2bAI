#include "note.h"

namespace midi_generator
{
    std::ostream& operator<<(std::ostream& os, const Note& note) {
        os << "Note(" << note.pitch << ", " << note.velocity << ", " << note.start << ", " << note.end << ")\n";
        return os;
    }
}
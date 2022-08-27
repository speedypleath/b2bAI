#pragma once
#include <iostream>

namespace midi_generator
{
    class Note;
}

class midi_generator::Note {
public:
    Note(int p, int v, double s, double e);
    ~Note();
    int pitch;
    int velocity;
    double start;
    double end; 
    bool operator==(const Note &rhs) const;
    bool operator!=(const Note &rhs) const;
    friend std::ostream& operator<<(std::ostream& os, const Note& note);
};
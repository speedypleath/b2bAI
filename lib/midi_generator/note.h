#pragma once
#include <iostream>

namespace midi_generator
{
    struct Note {
        Note(int p=0, int v=0, double s=.0f, double e=.0f) : pitch(p), velocity(v), start(s), end(e) {}
        int pitch;
        int velocity;
        double start;
        double end; 
        bool operator==(const Note &rhs) const {
            return pitch == rhs.pitch &&
                velocity == rhs.velocity &&
                start == rhs.start &&
                end == rhs.end;
        }

        bool operator!=(const Note &rhs) const {
            return !(rhs == *this);
        }

        friend std::ostream& operator<<(std::ostream& os, const Note& note);
    };
}
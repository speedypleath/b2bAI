from midi_generator.genetic import generator
from midi_generator.config import Configuration
from note import Note

def get_random_note():
    gen = generator(Configuration())
    gene = gen()
    return Note(gene.pitch, gene.velocity, 10, 20)

random_note = get_random_note()
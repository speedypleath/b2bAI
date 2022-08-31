from midi_generator.cli.commands import generate, mutate, melody_to_individual, check_remaining_ticks
from midi_generator.config import Configuration
from midi_generator.genetic import create_config, individual_to_melody


def test_generate():
    notes = generate(Configuration())
    print(notes)
    assert (notes is not None)


def test_mutate():
    config = Configuration()
    notes = generate(config)
    mutant = mutate(notes)

    assert (len(mutant) > 0)

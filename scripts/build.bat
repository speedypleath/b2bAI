ECHO ============================

ECHO INSTALL MIDI_GENERATOR

ECHO ============================

cd midi_generator

rmdir /S /Q dist
rmdir /S /Q midi_generator.egg-info

python -m build

pip install --force-reinstall dist/midi_generator-1.2-cp310-cp310-win_amd64.whl

flake8

pytest
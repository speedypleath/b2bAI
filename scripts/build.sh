#!/bin/bash

cd ../midi_generator || exit

# clean
rm -rf dist
rm -rf *.egg-info

# build the project
python3 -m build

# install the module
pip3 install --force-reinstall dist/*.whl

# run linter
flake8

# run tests
pytest
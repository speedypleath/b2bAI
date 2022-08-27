#!/bin/bash

cd ..

bash scripts/clean.sh

cd midi_generator

# build the project
python3 -m build

# install the module
pip3 install --force-reinstall dist/*.whl
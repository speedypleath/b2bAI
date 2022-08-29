.PHONY: config build clean test all

clion-build = cmake-build-debug
vscode_build = build
build = $(vscode_build)

all: | config build-lib build test run

config:
	cmake -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_BUILD_TYPE:STRING=Debug -DCMAKE_C_COMPILER:FILEPATH=/usr/bin/clang -DCMAKE_CXX_COMPILER:FILEPATH=/usr/bin/clang++ -S./ -B./${build} -G "Unix Makefiles"

build:
	make config
	cmake --build ./${build} --config Debug --target b2bAI_Standalone -j 6 --

build-lib:
	cmake --build ./${build} --config Debug --target midi_generator_ext -j 6 --

build-module:
	cd midi_generator; python3 -m build| pip3 install --force-reinstall dist/*.whl


clean:
	rm -rf ./${build}
	rm -rf .pytest_cache
	find . -type d -name '__pycache__' -exec rm -rf "{}" \;
	
test:
	cd tests; cmake --build .././${build}/tests --config Debug --target test_api -j 6 --| cmake --build .././${build}/tests --config Debug --target test_python -j 6 --| cmake --build .././${build}/tests --config Debug --target test_extract -j 6 --;
	pytest; cd cmake-build-debug/tests; ctest --rerun-failed --output-on-failure

run:
	cd build/vst/b2bAI_artefacts/Debug/Standalone/ && ./b2bAI
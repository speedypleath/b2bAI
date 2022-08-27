.PHONY: config build clean test all

all: | config build test run

config:
	/usr/bin/cmake --no-warn-unused-cli -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_BUILD_TYPE:STRING=Debug -DCMAKE_C_COMPILER:FILEPATH=/usr/bin/clang -DCMAKE_CXX_COMPILER:FILEPATH=/usr/bin/clang++ -S/home/speedypleath/b2bAI -B/home/speedypleath/b2bAI/build -G "Unix Makefiles"

build:
	make config
	/usr/bin/cmake --build /home/speedypleath/b2bAI/build --config Debug --target b2bAI_Standalone -j 6 --

clean:
	rm -rf build
	rm -rf .pytest_cache
	find . -type d -name '__pycache__' -exec rm -rf "{}" \;
	
test:
	cd lib;  cmake --build ../build --config Debug --target MidiGenerator -j 6 --
	cd tests; cmake --build ../build --config Debug --target test_executable -j 6 --
	cd build; ctest --rerun-failed --output-on-failure
	pytest

run:
	cd build/vst/plugin/b2bAI_artefacts/Debug/Standalone/ && ./b2bAI
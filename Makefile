
all: build

build: FORCE
	cmake --build build

setup:
	cmake -S . -B build

clean:
	rm -rf build/

install:
	cmake --install build

test:
	cd build && ctest

refresh: clean setup

FORCE: ;


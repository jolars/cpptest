
all: build

build: FORCE
	cmake --build build

setup:
	cmake -S . -B build

clean:
	rm -rf build/

install:
	cmake --install build

installbindings:
	cmake --install build/bindings

FORCE: ;


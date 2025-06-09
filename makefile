.PHONY: update_sources build clean test

PYTHON = python3

update_sources:
	@echo "Updating sources.cmake and test_sources.cmake..."
	@$(PYTHON) generate_sources.py
	@echo "Done."

build: update_sources
	mkdir -p build
	cmake -S . -B build
	cmake --build build

clean:
	rm -rf build/*

test: build
	cd build && ctest --output-on-failure

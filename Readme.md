# Gitfix

This tool acts as a **smart wrapper around `git`** to automatically correct typos in git subcommands. When a user misspells a git subcommand (e.g., `git chekout`), the tool identifies the intended command (`checkout`) and executes it seamlessly. User input is not modified, and the tool only corrects the command if it recognizes a typo.



A modern C++ project template with:

- [x] CMake build system
- [x] Automatic source / header list generation
- [x] Google Test integrated for unit testing
- [x]  Simple Makefile to drive builds and tests
- [x] Cross-platform friendly (macOS, Linux, Windows)

## Structure
```css
CppDevBase/
├── CMakeLists.txt
├── Makefile
├── generate_sources.py
├── sources.cmake (generated)
├── headers.cmake (generated)
├── test_sources.cmake (generated)
├── src/
│   └── main.cpp
├── include/
│   └── your_headers.hpp
├── tests/
│   └── your_tests.cpp
└── build/   (generated)

```


## Features
- C++20 standard
- Automatically updates sources.cmake and headers.cmake on build
- Automatic detection of test files under tests/
- gtest enabled
- Minimal Makefile for easy local builds


## Requirements
- CMake ≥ 3.18
- Python ≥ 3.6 (for generate_sources.py)
- A modern C++ compiler (GCC, Clang, Apple Clang, MSVC)


## Usage

### Build
```bash
make build
```

### Run tests
```bash
make test
```

### Clean artifacts
```bash
make clean
```

##Manually refresh sources
```
make update_sources
```

## Adding new files

### Source 
-  Source files in `src/`
- `.h` or `.hpp` files in `include/`

### Test
Add `.cpp` files to test and Google Test framework must be used


`generate_sources.py` automatically detects new files during make build

## Notes
The `build/` directory is auto-generated — not committed to source control.
`
This template is designed to be portable and extensible — suitable for CLI apps, libraries, and more.

## Future improvements
 - Pre-commit hook to auto-run generate_sources.py

- Support for clang-format and clang-tidy integration

- Optional install targets

- Support for building libraries in addition to executables
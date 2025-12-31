# object-oriented-cpp-labs

Welcome! This repo collects C++ labs and workshop exercises for practicing object-oriented programming concepts. It includes small examples, weekly projects, and tests built with CMake.

## What you are doing right now
- Working in the `object-oriented-cpp-labs` workspace on Linux via VS Code.
- Exploring and running C++ lab tasks (assignments, workshops, sandbox) with the provided build scripts.
- Using CMake-based builds; a helper script `scripts/run_cpp.sh` can run individual sources, and the `CMake: build + test` task drives the full build and test suite.

## Project layout (high level)
- `src/`, `include/`: Library sources and headers (e.g., `ExampleClass` and `tmp` helpers).
- `Project/`, `Assignments/`, `Workshops/`: Weekly lab and workshop exercises.
- `test/`: CTest-driven unit tests.
- `scripts/`: Utility scripts (`run_cpp.sh`, `build_and_test.sh`).
- `examples/`: Small standalone C++ examples demonstrating syntax and concepts.

## Build and run
- Full build and tests: run the VS Code task **CMake: build + test** (or `cmake -S . -B build && cmake --build build && ctest --test-dir build --output-on-failure`).
- Run a single C++ file with project includes: use the VS Code task **Run active C++ (with project lib)**, which wraps `scripts/run_cpp.sh`.

## Notes
- Code targets C++17 (see CMake and tasks).
- Generated build artifacts live in `build/` and `lib/Debug/`.
- Keep new files in ASCII unless there is a clear reason to include Unicode.

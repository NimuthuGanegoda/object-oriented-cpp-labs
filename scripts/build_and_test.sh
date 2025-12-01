#!/usr/bin/env bash
set -euo pipefail

BUILD_DIR="${BUILD_DIR:-build}"
CONFIG="${CONFIG:-Debug}"

cmake -S . -B "$BUILD_DIR" -Dobject-oriented-cpp-labs_BUILD_EXECUTABLE=ON
cmake --build "$BUILD_DIR" --config "$CONFIG"
ctest --test-dir "$BUILD_DIR" -C "$CONFIG" --output-on-failure

echo "Running binary (if present)"
if [[ -x "$BUILD_DIR/bin/$CONFIG/object-oriented-cpp-labs" ]]; then
  "$BUILD_DIR/bin/$CONFIG/object-oriented-cpp-labs" 2 3 || true
elif [[ -x "$BUILD_DIR/bin/object-oriented-cpp-labs" ]]; then
  "$BUILD_DIR/bin/object-oriented-cpp-labs" 2 3 || true
fi

#!/usr/bin/env bash
set -euo pipefail

if [[ $# -lt 1 ]]; then
  echo "Usage: $0 <file.cpp> [--with-lib] [--] [program-args...]" >&2
  exit 2
fi

CPP_FILE="$1"; shift || true
WITH_LIB=0
if [[ ${1:-} == "--with-lib" ]]; then
  WITH_LIB=1; shift
fi
if [[ ${1:-} == "--" ]]; then
  shift
fi

OUT_DIR="build/tmp"
BIN="$OUT_DIR/quick_run"
mkdir -p "$OUT_DIR"

CMD=(g++ -std=gnu++17 -O2 -pipe -Wall -Wextra -I include -o "$BIN" "$CPP_FILE")
if [[ $WITH_LIB -eq 1 ]]; then
  CMD+=(src/tmp.cpp)
fi

echo "Compiling: ${CMD[*]}" >&2
"${CMD[@]}"
echo "Running: $BIN $*" >&2
"$BIN" "$@"

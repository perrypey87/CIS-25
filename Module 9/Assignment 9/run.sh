#!/bin/bash

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"

# Check for g++
if ! command -v g++ &>/dev/null; then
    echo "ERROR: g++ not found. Run: xcode-select --install"
    read -p "Press Enter to close..."
    exit 1
fi

echo "Compiling..."
g++ -std=c++17 -o "$SCRIPT_DIR/inventory_system" \
    "$SCRIPT_DIR/main.cpp" \
    "$SCRIPT_DIR/functions.cpp"

if [ $? -ne 0 ]; then
    echo "Compilation failed."
    read -p "Press Enter to close..."
    exit 1
fi

echo "Done! Starting program..."
echo ""
"$SCRIPT_DIR/inventory_system"

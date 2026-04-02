#!/usr/bin/env bash
set -euo pipefail
echo "=== Installing QEMU ==="
if [[ "$(uname)" == "Darwin" ]]; then
    brew install qemu
elif [[ "$(uname)" == "Linux" ]]; then
    sudo apt-get update -qq
    sudo apt-get install -y -qq qemu-user qemu-user-static qemu-system-arm qemu-system-x86
fi
echo "=== QEMU installed ==="
qemu-x86_64 --version 2>/dev/null || echo "qemu-x86_64 not available"
qemu-aarch64 --version 2>/dev/null || echo "qemu-aarch64 not available"

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

# --- esp-qemu (Espressif fork for ESP32 bare-metal) ---
echo "=== Installing esp-qemu for ESP32 ==="

ESP_QEMU_VERSION="v8.2.0-esp"
ESP_QEMU_DIR="${HOME}/.esp-qemu"

if command -v qemu-system-xtensa &>/dev/null; then
    echo "qemu-system-xtensa already installed: $(qemu-system-xtensa --version | head -1)"
elif [[ "$(uname)" == "Darwin" ]]; then
    # Espressif maintains a Homebrew tap
    brew tap espressif/esp-idf || true
    brew install qemu-esp32 || echo "esp-qemu not available via brew; install manually from https://github.com/espressif/qemu/releases"
elif [[ "$(uname)" == "Linux" ]]; then
    # Download pre-built binary from Espressif releases
    ESP_QEMU_URL="https://github.com/espressif/qemu/releases/download/${ESP_QEMU_VERSION}/qemu-esp32-${ESP_QEMU_VERSION}-x86_64-linux-gnu.tar.gz"
    mkdir -p "${ESP_QEMU_DIR}"
    curl -L "${ESP_QEMU_URL}" | tar -xz -C "${ESP_QEMU_DIR}" --strip-components=1 || \
        echo "esp-qemu download failed; skipping (ESP32 QEMU tests will be skipped in CI)"
    export PATH="${ESP_QEMU_DIR}/bin:${PATH}"
fi

qemu-system-xtensa --version 2>/dev/null || echo "qemu-system-xtensa not available (ESP32 QEMU disabled)"

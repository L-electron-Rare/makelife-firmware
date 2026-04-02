#!/usr/bin/env bash
# ESP32 QEMU target — uses esp-qemu fork (qemu-system-xtensa)
# Requires: esp-qemu installed via qemu/install-qemu.sh
# UART output is parsed by parse_unity.py for Unity results

QEMU_CMD="qemu-system-xtensa"

# esp32 machine, 4MB flash image expected at FIRMWARE path
QEMU_ARGS=(
    "-nographic"
    "-machine" "esp32"
    "-drive" "file=${FIRMWARE}.bin,if=mtd,format=raw"
    "-serial" "stdio"
)

RESULT_METHOD="uart"

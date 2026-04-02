#!/usr/bin/env bash
# STM32 QEMU target — uses qemu-system-arm with netduinoplus2 machine
# Semihosting output is parsed by parse_unity.py for Unity results
# Requires firmware built with QEMU_BUILD=ON (semihosting linker flags)

QEMU_CMD="qemu-system-arm"

QEMU_ARGS=(
    "-nographic"
    "-machine" "netduinoplus2"
    "-kernel" "${FIRMWARE}"
    "-semihosting-config" "enable=on,target=native"
)

RESULT_METHOD="semihosting"

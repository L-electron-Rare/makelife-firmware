# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Overview

makelife-firmware is the multi-architecture firmware framework for FineFab. Portable HAL in C, CMake build system with presets per target, Unity tests on native host.

## Commands

```bash
# Build + test (native host)
cmake --preset native
cmake --build build/native
ctest --test-dir build/native --output-on-failure

# Build ESP32 (requires ESP-IDF toolchain)
cmake --preset esp32
cmake --build build/esp32

# Build STM32 (requires arm-none-eabi toolchain)
cmake --preset stm32
cmake --build build/stm32

# Build RP2040 (requires pico-sdk)
cmake --preset rp2040
cmake --build build/rp2040

# Build x86 (Linux host, release profile)
cmake --preset x86
cmake --build build/x86

# QEMU (bare-metal or user-mode)
cmake --preset native && cmake --build build/native
qemu-system-arm -machine ...    # see targets/qemu/ for per-target configs

# Run firmware locally (native)
timeout 5 build/native/app/firmware
```

## CMake Presets

5 presets defined in `CMakePresets.json`:

| Preset   | Target                | Notes                      |
| -------- | --------------------- | -------------------------- |
| `native` | Host (Linux/macOS)    | Unity tests, CI            |
| `esp32`  | ESP32                 | Requires ESP-IDF toolchain |
| `stm32`  | STM32 (nucleo-f446re) | Requires arm-none-eabi     |
| `rp2040` | RP2040 (pico)         | Requires pico-sdk          |
| `x86`    | x86 Linux             | Release profile            |

## Architecture

```text
hal/include/hal/    C interface headers (gpio.h, system.h) — portable, no arch deps
targets/native/     Stubs for host testing — log calls, simulate state
targets/esp32/      ESP-IDF implementation
targets/stm32/      STM32 HAL (nucleo-f446re board config)
targets/rp2040/     Pico SDK implementation (pico board config)
targets/x86/        Linux x86 target
targets/qemu/       QEMU configs — 5 target configs (bare-metal + user-mode)
app/                Application firmware — uses hal/ only, never arch-specific headers
tests/              Unity tests — compile and run on native only
lib/unity/          Vendored Unity test framework
legacy/             Old PlatformIO code (src/main.cpp, platformio.ini) — do not use
```

## Conventions

- App code includes only `hal/*.h` — never target-specific headers
- Tests run on `native` target only — no hardware dependency for CI
- New HAL interfaces: add header in `hal/include/hal/`, implement in each `targets/*/`
- Use `native_test_helpers.h` to inject values for testing
- PlatformIO is replaced by CMake — `legacy/` kept for reference only

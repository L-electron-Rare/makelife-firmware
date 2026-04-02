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

# Run firmware locally (native)
timeout 5 build/native/app/firmware
```

## Architecture

```text
hal/include/hal/    C interface headers (gpio.h, system.h) — portable, no arch deps
targets/native/     Stubs for host testing — log calls, simulate state
targets/esp32/      ESP-IDF implementation (stubs until cross-compile ready)
app/                Application firmware — uses hal/ only, never arch-specific headers
tests/              Unity tests — compile and run on native only
lib/unity/          Vendored Unity test framework
legacy/             Old PlatformIO code (src/main.cpp, platformio.ini)
```

## Conventions

- App code includes only `hal/*.h` — never target-specific headers
- Tests run on `native` target only — no hardware dependency for CI
- New HAL interfaces: add header in `hal/include/hal/`, implement in each `targets/*/`
- Use `native_test_helpers.h` to inject values for testing

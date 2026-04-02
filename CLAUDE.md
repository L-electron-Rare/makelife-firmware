# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Overview

makelife-firmware is the embedded firmware for FineFab hardware (ESP32). Built with PlatformIO and the Arduino framework, tested with Unity.

## Commands

```bash
# Build
pio run                     # All environments
pio run -e esp32dev         # ESP32 target only
pio run -e native           # Native (host) target only

# Test
pio test -e native          # Run Unity tests on host

# Flash
pio run -e esp32dev -t upload        # Flash to ESP32
pio run -e esp32dev -t monitor       # Serial monitor (115200 baud)
```

## Architecture

- `src/main.cpp` — Main firmware (setup/loop pattern, GPIO, Serial)
- `test/test_main.cpp` — Unity tests (run on native platform, not on hardware)
- `platformio.ini` — Build environments: `esp32dev` (target) and `native` (host tests)

## Hardware

- **Board**: ESP32 dev (espressif32 platform)
- **LED**: GPIO2 (`LED_BUILTIN`)
- **Serial**: 115200 baud
- **Debug toolchain**: xtensa-esp-elf (VS Code PlatformIO debugger configured)

## Conventions

- Status: v0.1.0, migrating from `Kill_LIFE/firmware`
- Keep Arduino framework patterns (setup/loop)
- Tests must run on `native` environment (no hardware dependency for CI)

# makelife-firmware

Embedded firmware for ESP32 and STM32 targets with PlatformIO and Unity test framework.

Part of the [FineFab](https://github.com/L-electron-Rare) platform (Factory 4 Life).

## What it does

- Provides production firmware for FineFab hardware boards
- Uses PlatformIO for cross-platform build and flash
- Includes Unity-based native and on-target test suites
- Supports OTA updates and CI-driven firmware publishing

## Tech stack

C++ | PlatformIO | Unity Test Framework | ESP-IDF

## Quick start

```bash
pio run              # Build firmware
pio test -e native   # Run native tests
pio run -t upload    # Flash to device
```

## Project structure

```
src/              Firmware source code
test/             Unity unit tests
platformio.ini    Build configuration and environments
```

## Related repos

| Repo | Role |
|------|------|
| [makelife-hard](https://github.com/L-electron-Rare/makelife-hard) | Hardware designs these firmwares target |
| [makelife-cad](https://github.com/L-electron-Rare/makelife-cad) | CAD/EDA web platform |
| [KIKI-models-tuning](https://github.com/L-electron-Rare/KIKI-models-tuning) | Model fine-tuning pipeline |
| [finefab-life](https://github.com/L-electron-Rare/finefab-life) | Integration runtime and ops |

## License

MIT

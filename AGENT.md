# Bitbusy Agent Guide

## Build Commands
- **ESP32 Firmware**: `pio run` (build), `pio run --target upload` (upload)
- **Web Frontend**: `cd front/bitbusy && npm run build` (build), `npm run check` (lint/type check)
- **Full Build**: `./build_page.sh` (builds frontend and copies to data/dist for ESP32 filesystem)

## Architecture
**Hardware**: ESP32 with WS2812 LED matrix (32x8), configured in `src/defines.h`
**Firmware**: C++/Arduino framework using PlatformIO. Core modules: `screens/` (display logic), `state/` (mode management), `timer/` (countdown), `web/` (HTTP API)
**Frontend**: Svelte 5 + TypeScript + Vite, serves as ESP32 web interface
**Communication**: ESPAsyncWebServer REST API between frontend and firmware

## Code Style
**C++**: Arduino-style with classes, snake_case functions, UPPER_CASE constants. Error handling via Serial output and return codes.
**TypeScript/Svelte**: camelCase, explicit types, async/await patterns. Components in `lib/`, utilities in root `src/`.
**Imports**: Grouped by standard library, third-party, then local. Use relative paths for local imports.
**Naming**: Descriptive names, avoid abbreviations. State management via dedicated classes. 

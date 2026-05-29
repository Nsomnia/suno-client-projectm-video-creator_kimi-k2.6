# Aether

A Qt6/QML multimedia application framework.

## Description

Aether is a next-generation multimedia application built on Qt6, leveraging Quick3D, advanced rendering pipelines, audio processing, and networking capabilities.

## Build Instructions

```bash
# Configure
cmake -B build -G Ninja

# Build
cmake --build build

# Run
./build/apps/aether/aether
```

## Requirements

- CMake >= 3.25
- Qt6 (Quick, Quick3D, ShaderTools)
- Ninja (recommended)
- C++23 capable compiler

## Project Structure

- `apps/aether/` — Main application entry point and QML UI
- `libs/core/` — Core utilities and foundational types
- `libs/rendering/` — Rendering engine and graphics abstractions
- `libs/audio/` — Audio processing and playback
- `libs/network/` — Networking and communication layer
- `libs/ui/` — Reusable UI components and theming
- `engine/` — High-level engine integration
- `themes/` — UI themes and stylesheets
- `shaders/` — Custom shader assets
- `assets/` — Fonts, images, and other static resources
- `config/` — Runtime configuration files
- `docs/` — Documentation
- `scripts/` — Build and utility scripts
- `testing/` — Test suites and benchmarks

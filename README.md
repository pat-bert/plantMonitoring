
# plantMonitoring

## Structure

| Path                               | Purpose                                                                                      |
| ---------------------------------- | -------------------------------------------------------------------------------------------- |
| _build                             | Stores build artifacts, can be deleted                                                       |
| cmake                              | Generated [CMake](https://cmake.org/) files. May be deleted if user.cmake has not been added |
| .vscode                            | See [VSCode Settings](https://code.visualstudio.com/docs/getstarted/settings)                |
| .vscode\plantMonitoring.mplab.json | The MPLAB project file, should not be deleted                                                |

## Flashing

MPLAB Snap is a cheap programmer that can be used to program the ATmega328p board via the ISCP header.
Make sure to use a USB cable shorter than 1.5 m to connect your PC to the Snap.
Otherwise you might see USB error: Transmission on endpoint 2 failed.

| Pin on Snap | Pin on MCU-ISCP|
| ------------|----------------|
| 1           | Do not connect |
| 2 (VTarget) | 2 (VCC)        |
| 3 (GND)     | 6 (GND)        |
| 4 (MISO)    | 1 (MISO)       |
| 5 (SCK)     | 3 (SCK)        |
| 6 (RESET)   | 5 (RESET)      |
| 7 (MOSI)    | 4 (MOSI)       |
| 8           | Do not connect |

# STM32 GPIO Driver Assignment

## Overview

This project demonstrates GPIO configuration and control using a custom STM32 GPIO driver on an STM32 Nucleo development board.

The project implements two tasks:

1. Button-Controlled LED Toggle
2. Alternating External LED Blinking

All GPIO operations are performed using the GPIO driver's APIs without direct register manipulation.

## Hardware Requirements

- STM32 Nucleo Development Board
- 2 External LEDs
- 2 Current-limiting resistors (220Ω or 330Ω)
- Breadboard
- Jumper wires
- USB cable

## Software Requirements

- STM32CubeIDE
- Embedded C
- STM32 GPIO Driver
- STM32 HAL/CMSIS dependencies, if applicable

## Task 1: Button-Controlled LED Toggle

### Description

The onboard user button is configured as a GPIO input, and the onboard user LED is configured as a GPIO output.

Whenever the user presses the button, the LED changes its state.

### Working Logic

- Button press detected.
- LED state toggled.
- LED remains in the new state after releasing the button.
- Debouncing is implemented to avoid multiple toggles from a single press.

### Expected Result

Each button press alternately turns the onboard LED ON and OFF.

## Task 2: Alternating External LED Blinking

### Description

Two GPIO pins are configured as outputs to control two external LEDs.

The LEDs blink alternately, with one LED ON while the other is OFF.

### GPIO Pin Configuration

| GPIO Pin | Configuration | Function |
|---|---|---|
| PA6 | Output | External LED 1 |
| PA7 | Output | External LED 2 |

*Update these pin mappings according to your actual hardware connections.*

### Working Logic

1. LED 1 ON, LED 2 OFF.
2. Wait 250 ms.
3. LED 1 OFF, LED 2 ON.
4. Wait 250 ms.
5. Repeat continuously.

Each LED has a 500 ms complete ON/OFF cycle.

## Wiring Diagram

For each external LED:

- PA6 → 220Ω resistor → LED 1 anode (+)
- LED 1 cathode (-) → GND
- PA7 → 220Ω resistor → LED 2 anode (+)
- LED 2 cathode (-) → GND

Ensure that the selected GPIO pins are available on your particular Nucleo board.

## Project Structure

```text
STM32-GPIO-Driver-Assignment/
│
├── Core/
│   ├── Inc/
│   │   ├── main.h
│   │   └── gpio.h
│   │
│   └── Src/
│       ├── main.c
│       └── gpio.c
│
├── Documentation/
│   └── wiring-diagram.png
│
├── README.md
├── .gitignore
└── LICENSE
```

*The actual project may contain additional STM32CubeIDE and driver dependency files.*

## Testing and Observations

- Verified onboard button input.
- Tested LED state toggling.
- Verified LED state persistence after button release.
- Tested alternating operation of two external LEDs.
- Observed continuous LED blinking with 250 ms switching intervals.
- Tested GPIO functionality on physical STM32 Nucleo hardware.

## Key Concepts Demonstrated

- STM32 GPIO initialization
- GPIO input and output configuration
- GPIO driver development and integration
- Button input handling
- LED control
- Software debouncing
- Busy-wait delay implementation
- Embedded C programming

## Demo

Add your hardware demonstration video link here.

## Author

**Akshay SR**

Embedded Firmware Engineer

GitHub: https://github.com/akshaysr801-cyber

# Motion Detector Alarm System

This project is a motion detector alarm system using LEDs and push buttons, designed as a school project. It has helped me practice combining software and hardware to create a real-life scenario. The project uses the Arduino Due microcontroller along with LEDs and push buttons to simulate a motion detection system.

## Components

- **Arduino Due**: The microcontroller board used for this project.
- **8 LEDs**: Represent different zones of the motion detection system.
- **2 Push Buttons**:
  - **PB1**: Starts the motion detection pattern.
  - **PB2**: Turns off all LEDs and deactivates the motion detection.

## Pin Configuration

- **LEDs**:
  - LED1: Pin 4
  - LED2: Pin 5
  - LED3: Pin 6
  - LED4: Pin 7
  - LED5: Pin 8
  - LED6: Pin 9
  - LED7: Pin 10
  - LED8: Pin 11
- **Push Buttons**:
  - PB1: Pin 12
  - PB2: Pin 13

## Functionality

- **Motion Detection Pattern**:
  - Pressing PB1 initializes the motion detection system and starts a pattern of blinking LEDs.
  - Each LED blinks at regular intervals, simulating motion detection in different zones.

- **Deactivation**:
  - Pressing PB2 turns off all LEDs, deactivating the motion detection system.

## Code Explanation

### Pin Definitions

Defines the pins for LEDs and push buttons.

### State Variables

Boolean variables to store the state (on/off) of each LED.

### `setup()` Function

- Configures the LED pins as output and push button pins as input with internal pull-up resistors.
- Attaches interrupts to the push buttons to handle state changes.
- Configures the timers to call specific handler functions.

### `loop()` Function

Continuously updates the state of the LEDs based on their state variables.

### Helper Function - `getHandler()`

Generates handler functions to toggle the state of the LEDs.

### `startPattern()` Function

- Debounces the button press to avoid accidental multiple triggers.
- Initializes all LED states to `false` (off).
- Starts the timers with increasing delays to create a blinking pattern.

### `turnOffLEDs()` Function

- Debounces the button press to avoid accidental multiple triggers.
- Sets all LED states to `false` (off) and stops the timers.

### Interrupt Handlers

Each timer interrupt handler toggles the state of its respective LED at regular intervals, creating a blinking pattern to indicate motion detection.

## Installation

1. Clone the repository:
    ```sh
    git clone https://github.com/yourusername/motion-detector-alarm.git
    ```
2. Open the project in the Arduino IDE.
3. Upload the code to your Arduino Due board.

## Usage

1. Connect the LEDs and push buttons to the specified pins.
2. Press PB1 to start the motion detection pattern.
3. Press PB2 to turn off all LEDs and deactivate the motion detection.

## Educational Impact

This project has been instrumental in helping me understand the integration of software and hardware to solve real-life problems. By working on this motion detector alarm system, I have gained practical experience in:

- Writing and understanding embedded C++ code.
- Utilizing hardware timers for precise control of outputs.
- Implementing debouncing techniques for reliable button inputs.
- Applying interrupt-driven programming for responsive systems.

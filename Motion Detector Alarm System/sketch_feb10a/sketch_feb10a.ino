#include <DueTimer.h> // Include the DueTimer library to use hardware timers

// Define the pins for LEDs and push buttons
const int LED_PINS[] = {4, 5, 6, 7, 8, 9, 10, 11}; // Array to store LED pin numbers
const int PB1 = 12, PB2 = 13; // Define pins for push buttons

volatile bool states[8] = {false}; // Array to store the state (on/off) of each LED
DueTimer* timers[8] = {&Timer0, &Timer1, &Timer2, &Timer3, &Timer4, &Timer5, &Timer6, &Timer7}; // Array of timer objects

void setup() {
  // Set up LED pins as OUTPUT
  for (int i = 0; i < 8; i++) pinMode(LED_PINS[i], OUTPUT);

  // Set up push button pins as INPUT_PULLUP
  pinMode(PB1, INPUT_PULLUP);
  pinMode(PB2, INPUT_PULLUP);

  // Attach interrupts to push buttons
  attachInterrupt(digitalPinToInterrupt(PB1), startPattern, FALLING);
  attachInterrupt(digitalPinToInterrupt(PB2), turnOffLEDs, FALLING);

  // Attach timer interrupts to handlers
  for (int i = 0; i < 8; i++) timers[i]->attachInterrupt(getHandler(i));
}

void loop() {
  // Continuously update the state of the LEDs based on their respective states
  for (int i = 0; i < 8; i++) digitalWrite(LED_PINS[i], states[i]);
}

// Helper function to generate handlers (requires C++11 or newer)
std::function<void()> getHandler(int idx) {
  return [idx]() { states[idx] = !states[idx]; }; // Toggle the state of the LED
}

// Function to start the LED pattern
void startPattern() {
  static unsigned long lastPress = 0;
  // Debounce to avoid accidental multiple triggers
  if (micros() - lastPress < 200000) return;
  lastPress = micros();
  
  // Initialize all LED states to false (LEDs off)
  for (int i = 0; i < 8; i++) {
    states[i] = false;
    timers[i]->stop();
    timers[i]->start(1000000 + i * 100000); // Start timers with increasing delays (1s, 1.1s, etc.)
  }
}

// Function to turn off all LEDs
void turnOffLEDs() {
  static unsigned long lastPress = 0;
  // Debounce to avoid accidental multiple triggers
  if (micros() - lastPress < 200000) return;
  lastPress = micros();
  
  // Set all LED states to false (LEDs off) and stop the timers
  for (int i = 0; i < 8; i++) {
    timers[i]->stop();
    states[i] = false;
  }
}

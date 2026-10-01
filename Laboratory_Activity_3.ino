/**
 * Laboratory Activity 3: GPIO and Button Control
 * Course: BCA188 - IoT Firmware Programming and Device I/O
 * Target Board: ESP32-S3
 * 
 * Description:
 * Controls two status LEDs using a single momentary tactile pushbutton.
 * - When the button is PRESSED: LED 1 is ON, LED 2 is OFF.
 * - When the button is RELEASED: LED 1 is OFF, LED 2 is ON (opposite state).
 * 
 * Pin Configuration Note (ESP32-S3):
 * GPIO 22, 23, 24, and 25 do not exist on the ESP32-S3.
 * We use GPIO 4 for the button, and GPIO 5 and 6 for the dual LEDs.
 */

#include <Arduino.h>

// Pin Definitions
const uint8_t BUTTON_PIN = 4;  // Tactile Pushbutton connected to GND (Active-LOW)
const uint8_t LED1_PIN   = 5;  // Main Status LED: ON when pressed, OFF when released
const uint8_t LED2_PIN   = 6;  // Secondary LED: OFF when pressed, ON when released (opposite)

void setup() {
  // Initialize Serial communication for optional debugging
  Serial.begin(115200);

  // Configure Button Pin with Internal Pull-Up Resistor (~45kΩ to 3.3V)
  // Pin reads HIGH when released, and LOW when pressed to GND
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // Configure LED pins as digital outputs
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);

  // Set initial states (Button is released at startup)
  digitalWrite(LED1_PIN, LOW);   // LED 1 starts OFF
  digitalWrite(LED2_PIN, HIGH);  // LED 2 starts ON (opposite state)

  Serial.println("System Initialized:");
  Serial.println("Initial State -> Button: RELEASED, LED 1: OFF, LED 2: ON");
}

void loop() {
  // Active-LOW evaluation:
  // When button is pressed, it shorts GPIO 4 to GND -> reads LOW
  const bool pressed = (digitalRead(BUTTON_PIN) == LOW);

  // LED 1 follows the button: lights up while button is held
  digitalWrite(LED1_PIN, pressed ? HIGH : LOW);

  // LED 2 shows the opposite state: lights up while button is released
  digitalWrite(LED2_PIN, pressed ? LOW : HIGH);
}

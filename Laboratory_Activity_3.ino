#include <Arduino.h>

const uint8_t BUTTON_PIN = 4;
const uint8_t LED1_PIN   = 5;
const uint8_t LED2_PIN   = 6;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);

  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, HIGH);
}

void loop() {
  const bool pressed = (digitalRead(BUTTON_PIN) == LOW);

  digitalWrite(LED1_PIN, pressed ? HIGH : LOW);

  digitalWrite(LED2_PIN, pressed ? LOW : HIGH);
}

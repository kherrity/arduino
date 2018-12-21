#include <Servo.h>

Servo servo;

const int neutral_pos = 10; // setting to zero causes servo vibration

void setup() {
  servo.attach(9); // digital pin 9
  servo.write(neutral_pos);
  delay(5000);
}

void servo_tilt(int degrees) {
  servo.write(neutral_pos + degrees);
}

// Feed Mr. Know-It-All every 24 hours
const unsigned long interval = 24UL * 60UL * 60UL * 1000UL;

void loop() {
  servo_tilt(105);
  delay(500);
  servo_tilt(0);
  unsigned long start = millis();
  while (millis() - start < interval);
}

#include <Servo.h>
int ledPins[] = {10, 11, 12, 13};
int buttonLedPins[] = {3, 4, 5, 6};
int ledFlags[] = {0, 0, 0, 0};
int servoPin = 7;
int buttonServoPin = 2;
int servoFlag = 0;
Servo servo;
void setup() {
  for (int i = 0; i < sizeof(ledPins); i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  for (int i = 0; i < sizeof(buttonLedPins); i++) {
    pinMode(buttonLedPins[i], INPUT);
  }
  pinMode(buttonServoPin, INPUT);
  servo.attach(servoPin);
  servo.write(0);// set servo to mid-point
}
void loop() {
    checkButtons();
}
void checkButtons() {
  if (digitalRead(buttonServoPin) == HIGH) {
    if (servoFlag == 0) {
      servoFlag = 1;
      changeGate(45);
    } else {
      servoFlag = 0;
      changeGate(90);
    }
  }
  for (int i = 0; i < sizeof(buttonLedPins); i++) {
    if (digitalRead(buttonLedPins[i]) == HIGH) {
      if (ledFlags[i] == 0) {
        ledFlags[i] = 1;
        digitalWrite(ledPins[i], HIGH);
      } else {
        ledFlags[i] = 0;
        digitalWrite(ledPins[i], LOW);
      }
    }
  }
  delay(500);
}
void changeGate(int x) {
  servo.attach(servoPin);
  servo.write(x);
  delay(1000);
}
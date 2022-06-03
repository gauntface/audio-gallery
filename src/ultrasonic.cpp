#include "ultrasonic.h"
#include <Arduino.h>

Ultrasonic::Ultrasonic(int triggerPin, int echoPin) {
    _triggerPin = triggerPin;
    _echoPin = echoPin;
}

long Ultrasonic::distanceInCM() {
  // Clears the trigger pin
  pinMode(_triggerPin, OUTPUT);
  digitalWrite(_triggerPin, LOW);
  delayMicroseconds(2);

  // Set the pin high to send audio
  digitalWrite(_triggerPin, HIGH);
  delayMicroseconds(10);

  // Set the pin to low to stop sending audio
  digitalWrite(_triggerPin, LOW);

  // Read the echo pin
  pinMode(_echoPin, INPUT);
  long duration = pulseIn(_echoPin, HIGH);

  // distance = time * speed
  // Divide by 2 to account for distance from sensor, to object and back
  // 0.034 cm/s is speed of sound
  return duration * 0.034 / 2;
}
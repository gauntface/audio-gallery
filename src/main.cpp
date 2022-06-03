#include <Arduino.h>
#include "ultrasonic.h"
#include "presence.h"

const boolean debug = false;
const int triggerPin = 2;
const int echoPin = 2;
const long acceptableDistance = 4;
const long waitInMills = 3000;

Ultrasonic ultrasonic(triggerPin, echoPin);
Presence presence(acceptableDistance, waitInMills);

void setup() {
  Serial.begin(9600);
  Serial.println("Audio Gallery - v1.0.0");
}

void onStateChange(bool presenceDetected) {
  if (presenceDetected) {
    Serial.println("Start playing music");
  } else {
    Serial.println("Stop playing music");
  }
}

void loop() {
  long distance = ultrasonic.distanceInCM();

  if (debug) {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }

  presence.update(distance, &onStateChange);
  delay(500);
}
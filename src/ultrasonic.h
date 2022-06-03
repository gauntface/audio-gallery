#ifndef Ultrasonic_H
#define Ultrasonic_H

class Ultrasonic {
  public:
    Ultrasonic(int triggerPin, int echoPint);
    long distanceInCM(void);
  private:
    int _triggerPin;
    int _echoPin;
};

#endif
#ifndef Presence_H
#define Presence_H

class Presence {
  public:
    Presence(long acceptableDistance, long waitInMillis);
    void update(long distance, void (*stateChangeCallback)(bool presenceDetected));
  private:
    long _acceptableDistance;
    long _waitInMillis;
    bool _isStablePresence;
    long _presenceStart;
    long _presenceEnd;
};

#endif
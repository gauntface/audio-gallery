#include "presence.h"
#include <Arduino.h>

Presence::Presence(long acceptableDistance, long waitInMillis) {
  _acceptableDistance = acceptableDistance;
  _waitInMillis = waitInMillis;
  _isStablePresence = false;
  _presenceStart = -1;
  _presenceEnd = -1;
}

void Presence::update(long distance, void (*stateChangeCallback)(bool presenceDetected)) {
  bool isPresent = distance <= _acceptableDistance;
  if (!isPresent) {
    if (!_isStablePresence) {
      return;
    }

    if (_presenceEnd < 0) {
      _presenceEnd = millis();
      return;
    }

    long elapsed = millis() - _presenceEnd;
    if (elapsed > _waitInMillis) {
      stateChangeCallback(false);
      _isStablePresence = false;
      _presenceStart = -1;
      _presenceEnd = -1;
    }
    return;
  }

  _presenceEnd = -1;

  if (_isStablePresence) {
    // Nothing to do since we know this
    // presence has been here a while.
    return;
  }

  if (_presenceStart < 0) {
    // This is the first time we've seen this
    // presence.
    _presenceStart = millis();
    return;
  }

  long elapsed = millis() - _presenceStart;
  if (elapsed > _waitInMillis) {
    stateChangeCallback(true);
    _isStablePresence = true;
  }
}
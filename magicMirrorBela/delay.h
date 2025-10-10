#pragma once
#include "effect.h"
#include "circularBuffer.h"

class Delay : public Effect
{
public:
  Delay() = default;
  Delay(float feedback, int samplesDelay, float dryWet);
  ~Delay(){}

  double applyEffect(double input) override;

private:
  CircularBuffer circBuffer;

  int samplesDelay = 0;
  float feedback = 0.0f;
  int samplerate = 44100;
  double output = 0.0;
};

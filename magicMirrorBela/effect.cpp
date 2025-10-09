#include "effect.h"
#include <iostream>

Effect::Effect(double dryWet) {
  setDryWet(dryWet);
}

Effect::~Effect() {}

// process frame
double Effect::processFrame(double input)
{
  double output;
  if (bypassOn == false) {
    output = input * wetDry + applyEffect(input) * dryWet;

    // TODO - WHY?: cache output samples
    m_sample = output;
  }
  else{output = input;}

  return output;
}

// returns the last outputted sample
double Effect::getSample()
{
  return m_sample;
}

void Effect::setDryWet(float dryWet)
{
  if(dryWet < 0 || dryWet > 1) {
    throw "Effect::setDryWet - dryWet value is not in range [0, 1]";
  }
  this->dryWet = dryWet;
  // cache 1.0 - dryWet used to calculate mix of dry wet signal
  wetDry = 1.0f - dryWet;
}

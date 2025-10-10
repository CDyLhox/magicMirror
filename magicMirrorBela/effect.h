#pragma once

class Effect
{
public:
  Effect(double dryWet = 1.0);
  virtual ~Effect();

  // process frame
  double processFrame(double input);
  // returns the last outputted sample
  double getSample();

  void setDryWet(float dryWet);

protected:
  virtual double applyEffect(double input) = 0;

private:
  // balance between dry and wet signal
  float dryWet;
  float wetDry; // = 1 - dryWet
  // cache last sample
  double m_sample;
  bool bypassOn = false;
};

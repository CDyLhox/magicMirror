#pragma once

class Effect
{
public:
  // drywet: drywet balance
  // drywet == 0:     dry
  // 0 < drywet < 1:  mix
  // drywet == 1:     wet
  // default is wet
  Effect(double dryWet = 1.0);
  virtual ~Effect();

  // not pure virtual, since not all subclasses require the samplerate
  virtual void prepare(double samplerate) { }
  // process frame
  double processFrame(double input);
  // returns the last outputted sample
  double getSample();

  void setDryWet(float dryWet);

protected:
  // pure virtual method
  virtual double applyEffect(double input) = 0;

private:
  // balance between dry and wet signal
  float dryWet;
  float wetDry; // = 1 - dryWet
  // cache last sample
  double m_sample;
  bool bypassOn = false;

};

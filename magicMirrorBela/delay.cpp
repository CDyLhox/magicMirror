#include "delay.h"
#include <iostream>

Delay::Delay(float feedback, int samplesDelay, float dryWet){

  setDryWet(dryWet);
  
  circBuffer.setBufferSize(samplesDelay+1);
  circBuffer.setNumSamplesDelay(samplesDelay);
  
  this-> feedback = feedback;
  this->samplesDelay = samplesDelay;
}

// applies delay effect to the input frame and stores it to the output frame
double Delay::applyEffect(double input){
    
  circBuffer.write(output * feedback + input);
  output = circBuffer.read();
  
  return output;
}

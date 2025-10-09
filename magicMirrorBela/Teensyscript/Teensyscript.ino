/* Mono Peak Meter
float readAveraged(byte pin, int samples=16) {
  unsigned long sum = 0;
  for (int i=0; i<samples; ++i) {
    sum += analogRead(pin);
    // small delay can help for very noisy sources: delayMicroseconds(50);
  }
  return (float)sum / samples / 1023.0; // normalized 0.0 - 1.0
}

   Scrolling peak audio level meter in the Arduino Serial Monitor
   adjusted for a mems microphone
   This example code is in the public domain
   */

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputI2S            i2s1;           //xy=119,52
AudioInputAnalog adc1(A2);
AudioAmplifier amp1;
AudioOutputI2S audioShield;
AudioControlSGTL5000 sgtl5000_1;
//
AudioAnalyzePeak         peak1;          //xy=379,43
AudioConnection          patchCord1(adc1, 0, peak1, 0);

AudioConnection          patchCord3(adc1,0,amp1,0);
AudioConnection           patchCord2(amp1, 0, audioShield, 0);
AudioConnection           patchCord4(amp1, 0, audioShield, 1);

  // GUItool: end automatically generated code

int gainPin = A7;


  void setup() {
    AudioMemory(4);
    Serial.begin(9600);
    //while(!Serial){;}
  amp1.gain(0.50);
  sgtl5000_1.enable();
  sgtl5000_1.volume(1);
  }

// for best effect make your terminal/monitor a minimum of 31 chars wide and as high as you can.

elapsedMillis fps;

float readAveraged(byte pin, int samples=200) {
  unsigned long sum = 0;
  for (int i=0; i<samples; ++i) {
    sum += analogRead(pin);
  }
  return (float)sum / samples / 1024.0; 
}

void loop() {


//  float gainread  = readAveraged(gainPin);
//  amp1.gain(gainread);
//  Serial.println(analogRead(A7));
  if (fps > 24) {
    if (peak1.available()) {
      fps = 0;
      int monoPeak = peak1.read() * 30.0;
      Serial.print("|");
      for (int cnt=0; cnt<monoPeak; cnt++) {
        Serial.print(">");
      }

      Serial.println();
    }
  }
}


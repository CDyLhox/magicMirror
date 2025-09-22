#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include "audioPlayer.h"

// GUItool: begin automatically generated code
AudioInputAnalog adc1(A2);
AudioAmplifier amp1;
AudioEffectDelay delay1;
AudioOutputPT8211_2 pt8211_2_1;
AudioOutputI2S i2s1;            //TODO: i2s1 ombouwen
AudioAnalyzePeak peak1;         //xy=512,410
AudioEffectEnvelope envelope1;  //xy=580,48
AudioControlSGTL5000 sgtl5000_1;

AudioConnection patchCord1(adc1, amp1);
AudioConnection patchCord2(amp1, delay1);
AudioConnection Patchcord(amp1, peak1);
AudioConnection Patchcord5(delay1, envelope1);
// AudioConnection patchCord3(envelope1, 0, pt8211_2_1, 0);
// AudioConnection patchCord4(envelope1, 0, pt8211_2_1, 1);
AudioConnection patchCord3(envelope1, 0, i2s1, 0);
AudioConnection patchCord4(envelope1, 0, i2s1, 1);

// AudioConnection patchCord3(amp1, 0, pt8211_2_1, 0); // STRAIGHT PASSTHROUGH FOR TESTING AND SANITY
// File myFile;

const int chipSelect = 10;
audioPlayer* player;


int gainPotPin = 21;
float gainPotRead = 1;
int ledPin = 23;
int peakValuePot = 20;
float peakValuePotRead;
elapsedMillis millistimer;

void setup() {
  Serial.begin(9600);

  player = new audioPlayer(chipSelect);
  while (!Serial) {
    ;  // wait for serial port to connect.
  }



  AudioMemory(240);
  amp1.gain(1.0);
  analogReadResolution(12);
  delay1.delay(0, 1000);

  sgtl5000_1.enable();
  sgtl5000_1.volume(20);

  pinMode(ledPin, OUTPUT);

  amp1.gain(1);
  digitalWrite(ledPin, HIGH);

  delay1.delay(0, 300);

  envelope1.attack(10);  // ms
  envelope1.hold(50);
  envelope1.decay(100);
  envelope1.sustain(0.5);
  envelope1.release(300);
}


void loop() {
  gainPotRead = analogRead(gainPotPin);
  // Serial.println(gainPotRead / 2000);

  // Serial.print("peakvaluepotread");
  // Serial.println(peakValuePotRead / 4000);
  peakValuePotRead = analogRead(peakValuePot);
  amp1.gain(gainPotRead / 2000);  // Resolution of 0 to 4 instead of 0 to 4048

  if (peak1.available()) {
    float peakVal = peak1.read();
    // Serial.println(peakVal);

    if (peakVal > peakValuePotRead / 4000) {  // root 4000 cause you want it from 0 to 1

      envelope1.noteOn();
      delay(300);
      envelope1.noteOff();
    }
  }
  // delay(150);
}
